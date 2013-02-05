#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "config.h"
#include <vector>
#include <iostream>

/**
 * ClockConfig represents a Config for the clock puzzle
 * @author Matthew Swain mds1482
 */
class ClockConfig : public Config<int> {
    public:
        /**
         * Constructs a ClockConfig object with the given information
         * @param hours number of hours on the clock
         * @param goal the hour that is trying to be reached
         */
        ClockConfig(int hours, int goal);

        /**
         * Displays the given state of the clock
         * @param state hour of the clock to be shown
         */
        virtual void display(const int &state) const;

        /**
         * Checks whether the goal condition for the clock has been met
         * @param state hour to check equality with the specified goal hour
         * @result whether the state matches the goal
         */
        virtual bool isGoal(const int &state) const;

        /**
         * Returns the 2 neighboring states for the given input state
         * @param state hour on the clock to find neighbors for
         * @param out vector to add the neighboring states to
         */
        virtual void nextConfigs(const int &state, std::vector<int> &out) const;

    private:
        int hours;
        int goal;
};


#endif
