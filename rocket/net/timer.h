#ifndef ROCKET_NET_TIMER_H_
#define ROCKET_NET_TIMER_H_
#include <map>
#include "rocket/net/fd_event.h"
#include "rocket/net/timer_event.h"
#include "rocket/common/mutex.h"

namespace rocket
{
    class Timer : public FdEvent
    {
    private:
        std::multimap<int64_t, TimerEvent::s_ptr> m_pending_events;
        Mutex m_mutex;

    public:
        Timer(int fd);
        Timer();
        ~Timer();

        void addTimerEvent(TimerEvent::s_ptr event);
        void deleteTimerEvent(TimerEvent::s_ptr event);

        void onTimer(); // 当发生了IO事件后，eventloop 会执行这个回调函数

    private:
        void resetArriveTime();
    };

} // namespace rocket

#endif