#ifndef WATERCONFIG_H
#define WATERCONFIG_H

#include "config.h"

#include <vector>

typedef std::vector<int> wc_state;

/**
 * This class is used to represent the water puzzle for part2
 * @author Matthew Swain mds1482
 */

class WaterConfig : public Config<wc_state> {
    public:

        /**
         * Constructor which initializes member variables based on parameters
         * @param goal Amount of water that is trying to be reached
         * @param capacities vector of ints which contains the capacity for
         *  each container
         */
        WaterConfig(int goal, wc_state &capacities);

        /**
         * Prints a representation of the given state to stdout
         * @param state state of the puzzle to be displayed
         */
        virtual void display(const wc_state &state) const;

        /**
         * Checks whether the specified goal has been reached
         * @param state state of the puzzle to check against the goal
         * @return whether this state meets the goal
         */
        virtual bool isGoal(const wc_state &state) const;

        /**
         * Returns a list of successive neighbor configs for the given state
         * @param state state of the puzzle to generate neighbors for
         * @param out vector in which to store the results of this method
         */
        virtual void nextConfigs(const wc_state &state, std::vector<wc_state> &out) const;

    private:
        int goal;
        wc_state capacity;
};


#endif
