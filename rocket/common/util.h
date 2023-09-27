#ifndef ROCKET_COMMON_UTIL_H_
#define ROCKET_COMMON_UTIL_H_


#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

namespace rocket
{
    pid_t getPid();
    pid_t getThreadId();
    int64_t getNowMs();
} // namespace rocket



#endif