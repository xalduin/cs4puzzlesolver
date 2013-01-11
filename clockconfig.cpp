#include "clockconfig.h"

#include <iostream>

using namespace std;

ClockConfig::ClockConfig(int h, int s, int g) :
    hours(h),
    goal(g)
{
    if( s <= 0 )
        state = hours - s;
    else if( s > hours )
        state = s - hours;
    else
        state = s;
}

ClockConfig::ClockConfig(const ClockConfig &other) :
    hours(other.hours),
    goal(other.goal),
    state(other.state)
{}

bool ClockConfig::operator==(const ClockConfig &other) const {
    return hours == other.hours && goal == other.goal && state == other.state;
}

bool ClockConfig::operator!=(const ClockConfig &other) const {
    return !( *this == other );
}

bool ClockConfig::operator<(const ClockConfig &other) const {
    return state < other.state;
}

void ClockConfig::display() const {
    cout << state << endl;
}

bool ClockConfig::isGoal() const {
    return state == goal;
}

void ClockConfig::nextConfigs(vector<ClockConfig> &out) const {
    out.push_back(ClockConfig(hours, state-1, goal));
    out.push_back(ClockConfig(hours, state+1, goal));
}
