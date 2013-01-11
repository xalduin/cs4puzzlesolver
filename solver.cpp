#include <map>
#include <queue>
#include <vector>

#include "solver.h"
#include "clockconfig.h"

using namespace std;

Solver::Solver(const ClockConfig &c) :
    _config(c)
{}

void Solver::solve(vector<ClockConfig> &out) {
    queue<ClockConfig> next;

    // Key = current config, value = parent config
    map<ClockConfig, ClockConfig> visited;
    ClockConfig current = _config;

    // The starting config doesn't really have a parent, but it needs to be
    // in the map
    visited.insert(pair<ClockConfig, ClockConfig>(_config, _config));

    // Find the shortest path solution
    while( !current.isGoal() ) {
        vector<ClockConfig> neighbors;
        current.nextConfigs(neighbors);

        // Add all new neighbors to the queue
        vector<ClockConfig>::iterator iter;
        for( iter = neighbors.begin(); iter != neighbors.end(); ++iter ) {
            ClockConfig &neighbor = *iter;

            bool inserted = visited.insert(pair<ClockConfig, ClockConfig>
                        (neighbor, current)).second;

            // Add to the "to be visisted" list unless this neighbor has been
            // visited
            if( inserted )
                next.push(neighbor);

        }

        current = next.front();
        next.pop();
    }

    out.push_back(current);
    ClockConfig parent = visited.find(current)->second;

    // Go backward through parent configs and add each config to the front
    // of the result vector
    while( current != parent ) {
        current = parent;
        out.insert(out.begin(), current);

        parent = visited.find(current)->second;
    }
}

