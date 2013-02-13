#ifndef MAGICCONFIG_H
#define MAGICCONFIG_H


#include "config.h"
#include <vector>

typedef  std::vector<int> mc_state;

class MagicConfig : public Config<mc_state> {
public:

    /**
     * Constructs a MagicConfig with the specified goal state
     * @param goal the state that must be reached to achieve the goal
     */
    MagicConfig(const mc_state &goal, int size);

    /**
     * Displays the given config state to stdout
     * @param state State of the config to display
     */
    virtual void display(const mc_state &state) const;

    /**
     * Displays whether the given state meets the goal condition
     * @param state State of the config to be checked
     * @return Whether the goal has been met
     */
    virtual bool isGoal(const mc_state &state) const;

    /**
     * Returns neighboring configs for a given state
     * @param state State to find neighbors for
     * @param out Vector where the resulting neighbors will be added to
     */
    virtual void nextConfigs(const mc_state &state,
            std::vector<mc_state> &out) const;

private:
    const int configSize;
    const mc_state goalState;
};


#endif
