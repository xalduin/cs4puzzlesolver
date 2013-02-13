#include "magicconfig.h"
#include "solver.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Program name + 8 numbers
const int NUM_ARGS = 9;
const char *USAGE_STRING = "magic # # # # # # # #";

int main(int argc, char *argv[]) {
    const int CONFIG_SIZE = 8;

    mc_state startState(CONFIG_SIZE);
    for( int i = 0; i < CONFIG_SIZE; ++i ) {
        startState[i] = i+1;
    }

    if( argc != NUM_ARGS ) {
        cout << "Usage: " << USAGE_STRING << endl;
        return EXIT_FAILURE;
    }

    mc_state goalState(CONFIG_SIZE);
    for( int i = 1; i < NUM_ARGS; ++i ) {
        int value = atoi(argv[i]);

        if( value < 1 || value > CONFIG_SIZE ) {
            cerr << "Entered out of range value : " << value << endl;
            return EXIT_FAILURE;
        }

        for( int j = 0; j < i - 1; ++j ) {
            int &val = goalState[j];
            if( val == value ) {
                cerr << "Entered duplicate value: " << value << endl;
                return EXIT_FAILURE;
            }
        }

        goalState[i-1] = value;
    }
    MagicConfig config(goalState, CONFIG_SIZE);

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
