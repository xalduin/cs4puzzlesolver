#include "clockconfig.h"

#include <iostream>

using namespace std;

ClockConfig::ClockConfig(int h, int g) :
    hours(h),
    goal(g)
{}

void ClockConfig::display(const int &state) const {
    std::cout << state << std::endl;
}

bool ClockConfig::isGoal(const int &state) const {
    return state == goal;
}

void ClockConfig::nextConfigs(const int &state, std::vector<int> &out) const {
    int before = state - 1;
    int after  = state + 1;

    if( before < 1 )
        before = hours - before;

    if( after > hours )
        after -= hours;

    out.push_back(before);
    out.push_back(after);
}
