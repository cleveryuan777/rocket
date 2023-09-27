#ifndef ROCKET_COMMON_CONFIG_H_
#define ROCKET_COMMON_CONFIG_H_

#include <map>

namespace rocket
{
    class Config
    {
    public:
        Config(const char *xmlfile);

    public:
        static Config * GetGlobalConfig();
        static void SetGlobalConfig(const char *xmlfile);
    public:
        std::string m_log_level;
    };
}

#endif