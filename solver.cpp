#include <queue>
#include <vector>
#include <map>
#include "solver.h"

using namespace std;

Solver::Solver(const Config &c) :
    _config(c)
{}

Solver::solve(vector<ClockConfig> &out) {
    queue<ClockConfig> next;

    // Key = current config, value = parent config
    map<ClockConfig, ClockConfig> visisted;
    ClockConfig current = _config

    visited[_config] = _config;

    // Find the shortest path solution
    while( !current.isGoal() ) {
        vector<ClockConfig> neighbors;
        current.nextConfigs(neighbors);

        // Add all new neighbors to the queue
        vector<ClockConfig>::iterator iter;
        for( iter = neighbors.begin(); iter != neighbors.end(); iter++ ) {
            ClockConfig neighbor = *iter;
            
            bool inserted = visited.insert(pair<ClockConfig, ClockConfig>
                        (neighbor, current));

            if( inserted )
                next.push(neighbor);
        }

        current = next.pop();
    }

    out.push_back(current);
    ClockConfig from = visited[current];

    while( current != from ) {
        current = from;
        out.insert(out.begin(), current);
        from = visited[current];
    }
}

