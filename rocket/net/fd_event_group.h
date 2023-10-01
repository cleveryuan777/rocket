#ifndef ROCKET_NET_FDEVENT_GROUP_H_
#define ROCKET_NET_FDEVENT_GROUP_H_

#include "rocket/net/fd_event.h"
#include "rocket/common/mutex.h"
#include <vector>

namespace rocket
{
    class FdEventGroup
    {
    private:
        int m_size{0};
        std::vector<FdEvent *> m_fd_group;
        Mutex m_mutex;

    public:
        FdEventGroup(int size);
        ~FdEventGroup();
        FdEvent* getFdEvent(int fd);
    public:
        static FdEventGroup* GetFdEventGroup();
    };
} // namespace rocket

#endif