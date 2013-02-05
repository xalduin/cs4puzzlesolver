#include "waterconfig.h"
#include "solver.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Minimum number of args = program goal container1
const int NUM_MIN_ARGS = 3;
const char* USAGE_STRING = "water goal_volume container1 ... containerN";

/**
 * @pre All strings passed to program are valid ints
 */
int main(int argc, const char* argv[]) {

    if( argc < NUM_MIN_ARGS ) {
        cout << "Usage: " << USAGE_STRING << endl;
        return EXIT_SUCCESS;
    }

    int goal = atoi(argv[1]);

    // Read in the container sizes from the args
    vector<int> containers;
    for( int i = 2; i < argc; ++i ) {
        int capacity = atoi(argv[i]);

        if( capacity <= 0 ) {
            cerr << "Invalid capacity: '" << capacity <<
                "' for container #" << i << endl;
            return EXIT_SUCCESS;
        }

        containers.emplace_back(capacity);
    }

    WaterConfig config(goal, containers);

    vector<int> startState(argc - 2, 0);
    vector< vector<int> > solution;
    bool result = solveConfig(config, startState, solution);

    // Make sure a solution was found (possible that none exists)
    if( !result ) {
        cout << "No solution found!" << endl;
        return EXIT_SUCCESS;
    }
    
    // Show the solution
    for( unsigned int i = 0; i < solution.size(); ++i ) {
        cout << "Step " << i << ":";
        config.display(solution.at(i));
    }
}
