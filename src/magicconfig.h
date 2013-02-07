#ifndef MAGICCONFIG_H
#define MAGICCONFIG_H


#include "config.h"
#include <array>
#include <vector>
#include <boost/functional/hash.hpp>

const int CONFIG_SIZE = 8;
typedef std::array<int, CONFIG_SIZE> mc_state;

class MagicConfig : public Config<mc_state> {
public:

    /**
     * Constructs a MagicConfig with the specified goal state
     * @param goal the state that must be reached to achieve the goal
     */
    MagicConfig(mc_state goal);

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

public:
    static const int configSize;
private:
    const mc_state goalConfig;
};


namespace std {
    template <>
    struct hash<mc_state>{
    public :
        size_t operator()(const mc_state &v ) const
        {
            return boost::hash_range(v.begin(), v.end());
        }
    };
}

#endif
