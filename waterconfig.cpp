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
    wc_state::const_iterator iter;
    for( iter = state.begin(); iter != state.end(); ++iter )
        cout << " " << *iter;

    cout << endl;
}

bool WaterConfig::isGoal(const wc_state &state) const {
    wc_state::const_iterator iter;
    for( iter = state.begin(); iter != state.end(); ++iter )
        if( *iter == goal )
            return true;

    return false;
}

void WaterConfig::nextConfigs(const wc_state &state, vector<wc_state> &out) const {

    // Generate neighbor configs for each bucket/container of water
    for( unsigned int current = 0; current < state.size(); ++current ) {

        // Change in state 1: dump bucket
        // Only dump the bucket if there's something in it
        if( state[current] > 0 ) {
            wc_state dumpState(state);
            dumpState[current] = 0;
            out.push_back(dumpState);
        }

        // Change in state 2: fill bucket
        // Only fill if bucket isn't already full
        if( state[current] < capacity[current] ) {
            wc_state fillState(state);
            fillState[current] = capacity[current];
            out.push_back(fillState);
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

            wc_state pourState(state);

            // The amount being transferred is either:
            //  -Enough to fill the current bucket
            //  -Enough to empty the 'other' bucket
            int amount = min(capacity[current] - state[current], state[other]);

            pourState[current] = state[current] + amount;
            pourState[other]   = state[other] - amount;

            out.push_back(pourState);
        }
    }
}
