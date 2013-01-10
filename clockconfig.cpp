#include "clockconfig.h"

using std::vector;

ClockConfig::ClockConfig(const int h, int s, const int g) :
    hours(h),
    goal(g)
{
    if( s <= 0 )
        state = hours - s;
    else if( s > hours )
        state = s - hours;
}

ClockConfig::ClockConfig(const ClockConfig &other) :
    hours(other.hours),
    goal(other.goal),
    state(other.state)
{}

bool ClockConfig::isGoal() const {
    return state == goal;
}

void ClockConfig::nextConfigs(vector<ClockConfig> &out) const {
    out.push_back(ClockConfig(hours, goal, state-1));
    out.push_back(ClockConfig(hours, goal, state+1));
}
