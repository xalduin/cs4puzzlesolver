#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <vector>

class ClockConfig {
    public:
        ClockConfig(int hours, int start, int goal);
        ClockConfig(const ClockConfig &other);

        bool operator==(const ClockConfig &other) const;
        bool operator!=(const ClockConfig &other) const;
        bool operator<(const ClockConfig &other) const;

        void display() const;
        bool isGoal() const;
        void nextConfigs(std::vector<ClockConfig>& out) const;

    private:
        int hours;
        int goal;
        int state;
};

#endif
