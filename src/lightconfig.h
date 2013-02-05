#ifndef LIGHTCONFIG_H
#define LIGHTCONFIG_H

#include "config.h"
#include <vector>
#include <ostream>

typedef std::vector<std::vector<char>> lc_state;

const char LIGHT_OFF        = '.';
const char LIGHT_ON         = '*';
const char LIGHT_ALWAYS_OFF = '0';
const char LIGHT_ALWAYS_ON  = '1';

class LightConfig : public Config<lc_state> {
    public:

        /**
         * Constructor which initializes the class with a given goal
         * @param goal number of lights that need to be turned on
         */
        LightConfig(int goal);

        /**
         * Displays the current state of the config
         * @param state state to display
         */
        virtual void display(const lc_state &state) const;

        /**
         * Displays current state of config on the given output stream
         * @param state state to display
         * @param out ostream to use for output
         */
        void display(const lc_state &state, std::ostream &out) const;

        /**
         * Checks whether a certain state has met the goal conditions
         * @param state state to be checked against the goal
         * @return whether the goal has been met
         */
        virtual bool isGoal(const lc_state &state) const;

        /**
         * Returns neighboring conigs for a given state
         * @param state state to find neighbors to
         * @param out vector where resulting neighbors will be added to
         */
        virtual void nextConfigs(const lc_state &state,
                std::vector<lc_state> &out) const;

    private:

        /**
         * Returns whether the light at the given row/col can have its state
         * changed
         * @param state state to be checked
         * @param row row of the state to be checked
         * @param col column of the state to be checked
         * @result whether the light at row/col can be changed
         */
        bool canChange(const lc_state &state, int row, int col) const;

    private:
        int lightCountGoal;
};

#endif
