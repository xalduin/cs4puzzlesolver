#include "magicconfig.h"
#include "solver.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Program name + 8 numbers
const int NUM_ARGS = MagicConfig::configSize + 1;
const char *USAGE_STRING = "magic # # # # # # # #";
const mc_state startState = {1, 2, 3, 4, 5, 6, 7, 8};

int main(int argc, char *argv[]) {

    if( argc != NUM_ARGS ) {
        cout << "Usage: " << USAGE_STRING << endl;
        return EXIT_FAILURE;
    }

    mc_state goalState;
    for( int i = 1; i < NUM_ARGS; ++i ) {
        int value = atoi(argv[i]);

        if( value < 1 || value > MagicConfig::configSize ) {
            cerr << "Entered out of range value : " << value << endl;
            return EXIT_FAILURE;
        }

        // Check to see if the value was previously specified
        for( auto &val : goalState ) {
            if( val == value ) {
                cerr << "Entered duplicate value: " << value << endl;
                return EXIT_FAILURE;
            }
        }

        goalState.push_back(value);
    }
    MagicConfig config(goalState);

    // There should always be a solution to this puzzle
    vector<mc_state> solution;
    solveConfig(config, startState, solution);

    int step = 0;
    for( auto &state : solution ) {
        cout << "Step " << step++ << ":" << endl;
        config.display(state);
        cout << endl;
    }

    return EXIT_SUCCESS;
}
