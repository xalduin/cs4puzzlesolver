#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

class Config {
    public:
        virtual bool isGoal();
        virtual nextConfigs(std::vector<Config>& out);
}

#endif
