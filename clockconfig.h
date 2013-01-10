#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <vector>

class ClockConfig {
    public:
        ClockConfig(const int hours, int start, const int goal);
        ClockConfig(const ClockConfig &other);

        bool isGoal() const;
        void nextConfigs(std::vector<ClockConfig>& out) const;

    private:
        const int hours;
        const int goal;
        int state;
};

#endif
