#ifndef CONFIG_H
#define CONFIG_H

#include <vector>


/**
 * Config is used by the solveConfig function to get necessary information
 *  about the puzzle being solved
 *
 * @author Matthew Swain mds1482
 */

template <typename T>
class Config {
    public:
        /**
         * Displays the given config state
         * @param state State of the config to display
         */
        virtual void display(const T &state) const = 0;

        /**
         * Checks whether a certain state has met the goal conditions
         * @param state State to check against the goal condition
         * @return Whether or not the goal has been met
         */
        virtual bool isGoal(const T &state) const = 0;

        /**
         * Returns the neighboring configs for a given state
         * @param state State to find the neighbors to
         * @param out Vector where the resulting neighbors will be added to
         */
        virtual void nextConfigs(const T &state, std::vector<T> &out) const = 0;
};


#endif
