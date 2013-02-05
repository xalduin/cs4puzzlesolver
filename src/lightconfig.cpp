#include "lightconfig.h"

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

LightConfig::LightConfig(int goal) :
    lightCountGoal(goal)
{}

void LightConfig::display(const lc_state &state) const {
    display(state, cout);
}

void LightConfig::display(const lc_state &state, ostream &out) const {
    for( auto &row : state ) {
        for( auto &col : row ) {
            out << col;
        }
        out << "\n";
    }
    out.flush();
}

bool LightConfig::isGoal(const lc_state &state) const {
    int count = 0; 
    for( auto &row : state )
        for( auto &col : row )
            if( col == LIGHT_ON || col == LIGHT_ALWAYS_ON )
                count++;

    return count == lightCountGoal;
}

bool LightConfig::canChange(const lc_state &state, int row, int col) const {
    for (int r = row - 1; r <= row + 1; ++r ) {
        for (int c = col - 1; c <= col + 1; ++c) { 

            if (r < 0 || c < 0 || r >= state.size() || c >= state[0].size() )
                continue;

            auto light = state[r][c];

            if (light == LIGHT_ALWAYS_ON || light == LIGHT_ALWAYS_OFF)
                return false;
        }
    }

    return true;
}

bool changeLight(lc_state &state, int row, int col) {
    for (int r = row - 1; r <= row + 1; r++) {

        vector<int> cols;

        if( r == row ) {
            for( int c = col - 1; c <= col + 1; ++c ) {
                cols.push_back(c);
            }
        }
        else {
            cols.push_back(col);
        }

        for( auto c : cols ) {
            if( r < 0 || c < 0 || r >= state.size() || c >= state[0].size() )
                continue;

            char &light = state[r][c];

            if( light == LIGHT_ALWAYS_ON || light == LIGHT_ALWAYS_OFF )
                return false;
            else if( light == LIGHT_ON )
                light = LIGHT_OFF;
            else
                light = LIGHT_ON;
        }
    }

    return true;
}

void LightConfig::nextConfigs(const lc_state &state, vector<lc_state> &out) const {
    int rows = state.size();
    int cols = state[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {

            lc_state nextState(state);

            if( !changeLight(nextState, row, col) )
                continue;

            out.emplace_back(std::move(nextState));
        }
    }
}
