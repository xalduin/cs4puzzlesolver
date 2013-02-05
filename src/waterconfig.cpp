#include "waterconfig.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

WaterConfig::WaterConfig(int g, wc_state &c) :
    goal(g),
    capacity(c)
{}

void WaterConfig::display(const wc_state &state) const {
    for( auto &container : state )
        cout << " " << container;

    cout << endl;
}

bool WaterConfig::isGoal(const wc_state &state) const {
    for( auto &container : state )
        if( container == goal )
            return true;

    return false;
}

void WaterConfig::nextConfigs(const wc_state &state, vector<wc_state> &out) const {

    // Generate neighbor configs for each bucket/container of water
    for( unsigned int current = 0; current < state.size(); ++current ) {

        // Change in state 1: dump bucket
        // Only dump the bucket if there's something in it
        if( state[current] > 0 ) {
            out.emplace_back(state);
            out.back()[current] = 0;
        }

        // Change in state 2: fill bucket
        // Only fill if bucket isn't already full
        if( state[current] < capacity[current] ) {
            out.emplace_back(state);
            out.back()[current] = capacity[current];
        }

        // Change in state 3: fill from another bucket
        // Don't bother if this bucket is already full
        if( state[current] == capacity[current] )
            continue;

        for( unsigned int other = 0; other < state.size(); ++other ) {

            // 1. A bucket can't fill itself
            // 2. An empty bucket can't fill anything
            if( other == current || state[other] == 0 )
                continue;

            out.emplace_back(state);

            // The amount being transferred is either:
            //  -Enough to fill the current bucket
            //  -Enough to empty the 'other' bucket
            int amount = min(capacity[current] - state[current], state[other]);

            out.back()[current] = state[current] + amount;
            out.back()[other] = state[other] - amount;
        }
    }
}
