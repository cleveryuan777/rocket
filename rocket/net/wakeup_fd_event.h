#ifndef ROCKET_NET_WAKEUP_FDEVENT_H_
#define ROCKET_NET_WAKEUP_FDEVENT_H_

#include "rocket/net/fd_event.h"

namespace rocket
{

    class WakeUpFdEvent : public FdEvent
    {
    private:
        /* data */
    public:
        WakeUpFdEvent(int fd);
        ~WakeUpFdEvent();

        void wakeup();
    };

}

#endif