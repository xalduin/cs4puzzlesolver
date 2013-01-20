#ifndef SOLVER_H
#define SOLVER_H

#include "config.h"

#include <map>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void solveConfig(const Config<T> &config, const T &start, vector<T> &out) {
    queue<T> next;

    // Key = current state, value = parent state
    map<T, T> visited;

    // The starting config doesn't really have a parent, but it needs to be
    // in the map
    visited.insert(pair<T, T>(start, start));

    // Find the shortest path solution
    T current = start;
    while( !config.isGoal(current) ) {
        vector<T> neighbors;
        config.nextConfigs(current, neighbors);

        // Add all new neighbors to the queue
        for( unsigned int i = 0; i < neighbors.size(); ++i ) {
            T &neighbor = neighbors[i];

            bool insert = visited.insert(pair<T, T>(neighbor, current)).second;
            
            // Add to the "to be visited" list unless neighbor has been
            // visited
            if( insert )
                next.push(neighbor);
        }

        current = next.front();
        next.pop();
    }

    out.push_back(current);

    // Go backward through parent states and add each state to the front
    // of the result vector
    while( current != start ) {
        current = visited.find(current)->second;
        out.insert(out.begin(), current);
    }

    // Doesn't refer to memory on the heap so delete isn't necessary
    current = 0;
}







#endif
