#include "lightconfig.h"
#include "solver.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int NUM_ARGS = 4;
const char *USAGE_STRING = "light input_source output_source num_lights";

bool readInput(string source, lc_state &outState) {
    istream *in = 0;
    ifstream *fin = 0;

    if( source == "-" ) {
        in = &cin;
    }
    else {
        fin = new ifstream(source);
        if( !fin->is_open() ) {
            cerr << "Unable to open '" << source << "' for input" << endl;
            delete fin;
            return false;
        }
        in = fin;
    }

    // The first line is: row col<newline>
    int rows, cols;
    (*in) >> cols;
    in->get();
    (*in) >> rows;
    
    // Finish reading the remainder of the row including the newline
    string line;
    getline(*in, line);

    for( int r = 0; r < rows; r++ ) {
        std::getline(*in, line);

        vector<char> rowState;

        for(int c = 0; c < cols; ++c) {
            rowState.push_back(line[c]);
        }

        outState.push_back(std::move(rowState));
    }

    if( fin ) {
        fin->close();
        delete fin;
    }

    return true;
}

int main(int argc, const char *argv[]) {

    if (argc != NUM_ARGS) {
        cout << "Usage: " << USAGE_STRING << endl;
        return EXIT_SUCCESS;
    }

    int goal = atoi(argv[3]);

    string infile = argv[1];
    string outfile = argv[2];

    lc_state startState;
    if( !readInput(infile, startState) ) {
        cerr << "Failed to read '" << infile << endl;
        return EXIT_FAILURE;
    }

    ostream *out;
    ofstream *fout = 0;

    if( outfile == "-" )
        out = &cout;
    else {
        fout = new ofstream(outfile);

        if( !fout->is_open() ) {
            cerr << "Failed to open '" << outfile << "' for output" << endl;

            delete fout;
            fout = 0;
            return EXIT_FAILURE;
        }

        out = fout;
    }

    vector<lc_state> solution;
    LightConfig config(goal);
    string result;

    if( !solveConfig(config, startState, solution) ) {
        (*out) << "no solution exists" << endl;
    }
    else {
        int step = 0;
        for( auto &state : solution ) {
            (*out) << "Step " << step++ << endl;
            config.display(state, *out);
            (*out) << endl;
        }
    }

    if( fout ) {
        fout->close();
        delete fout;
    }
}
