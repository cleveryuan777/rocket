#ifndef ROCKET_COMMON_RUN_TIME_H_
#define ROCKET_COMMON_RUN_TIME_H_

#include <string>

namespace rocket
{
    class RunTime
    {
    public:
        std::string m_msg_id;
        std::string m_method_name;

    public:
        static RunTime *GetRunTime();
    };


} // namespace rocket

#endif