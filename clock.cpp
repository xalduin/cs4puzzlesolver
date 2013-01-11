#include "clockconfig.h"
#include "solver.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const int NUM_ARGUMENTS = 4;
const char* USAGE_STRING = "clock num_hours start stop";

/**
 * Pre: All strings passed to program are valid ints
 */
int main(int argc, const char* argv[]) {
    
    if( argc != NUM_ARGUMENTS ) {
        cout << "Usage: " << USAGE_STRING << endl;
        return EXIT_SUCCESS;
    }

    int hours = atoi(argv[1]);
    int start = atoi(argv[2]);
    int stop  = atoi(argv[3]);

    if( hours <= 0 ) {
        cerr << "Invalid number of hours" << endl;
        return EXIT_SUCCESS;
    }
    else if( start <= 0 || start > hours ) {
        cerr << "Invalid start time" << endl;
        return EXIT_SUCCESS;
    }
    else if( stop <= 0 || stop > hours ) {
        cerr << "Invalid end time" << endl;
        return EXIT_SUCCESS;
    }

    ClockConfig startConfig(hours, start, stop);
    Solver solver(startConfig);

    vector<ClockConfig> solution;
    solver.solve(solution);

    // Display each step of the solution
    for( unsigned int i = 0; i < solution.size(); ++i ) {
        cout << "Step " << i << ": ";
        solution.at(i).display();
    }
}
