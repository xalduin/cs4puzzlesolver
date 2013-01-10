#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "clockconfig.h"

class Solver {
    public:
        Solver(const ClockConfig &c);
        void solve(std::vector<ClockConfig> &out);

    private:
        const ClockConfig _config;
};

#endif
