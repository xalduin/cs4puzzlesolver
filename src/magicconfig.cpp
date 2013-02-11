#include "magicconfig.h"

#include <iostream>
#include <vector>
#include <algorithm> // For c++03
#include <utility>   // For c++11

using namespace std;

// Assumes that configSize is a multiple of 4
const int MagicConfig::configSize = 8;

MagicConfig::MagicConfig(mc_state goal) :
    goalConfig(goal)
{}

void MagicConfig::display(const mc_state &state) const {

    const int halfSize = configSize / 2;

    for( int i = 0; i < halfSize; ++i ) {
        cout << state[i];
        if( i != halfSize-1 )
            cout << " ";
    }
    cout << endl;

    for( int i = configSize-1; i >= halfSize; --i ) {
        cout << state[i];
        if( i != halfSize )
            cout << " ";
    }
    cout << endl;
}

bool MagicConfig::isGoal(const mc_state &state) const {
    for( int i = 0; i < configSize; ++i ) {
        if( state[i] != goalConfig[i] )
            return false;
    }
    return true;
}

void MagicConfig::nextConfigs(const mc_state &s, vector<mc_state> &out) const {

    const int halfSize = configSize / 2;
    const int quarterSize = halfSize / 2;
    // Three methods of generating an alternate configuration

    // Step one: swap the bottom half and top half
    mc_state newState;
    copy(s.begin(), s.end(), newState.begin());
    for( int i = 0; i < halfSize; ++i ) {
        swap(newState[i], newState[configSize-i-1]);
    }
    out.push_back(newState);

    // Step 2: "Rotate" each half to the right
    // 1 2 3 4 -> 4 1 2 3
    // 8 7 6 5 -> 5 8 7 6
    
    copy(s.begin(), s.end(), newState.begin());
    for( int i = 0; i < halfSize-1; i++ ) {
        swap(newState[halfSize - 1 - i], newState[halfSize - 2 - i]);
        swap(newState[halfSize + i], newState[halfSize + 1 + i]);
    }
    out.push_back(newState);

    // Step 3: Clockwise rotation of 4 middle numbers
    // 1 2 3 4 -> 1 7 2 4
    // 8 7 6 5 -> 8 6 3 5

    copy(s.begin(), s.end(), newState.begin());
    swap(newState[quarterSize-1], newState[quarterSize]);
    swap(newState[quarterSize-1], newState[halfSize+quarterSize]);
    swap(newState[halfSize+quarterSize], newState[halfSize+quarterSize-1]);
    out.push_back(newState);
}


