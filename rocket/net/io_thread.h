#ifndef ROCKET_NET_IO_THREAD_H_
#define ROCKET_NET_IO_THREAD_H_

#include "rocket/net/eventloop.h"
#include <pthread.h>
#include <semaphore.h>

namespace rocket
{
    class IOThread
    {
    public:
        IOThread();
        ~IOThread();

        EventLoop *getEventLoop();

        void start();

        void join();

    public:
        static void *Main(void *arg);

    private:
        pid_t m_thread_id{-1};            // 线程号
        pthread_t m_thread{-1};           // 线程句柄
        EventLoop *m_event_loop{nullptr}; // 当前 io 线程的 loop对象
        sem_t m_init_semaphore;
        sem_t m_start_semaphore;
    };
} // namespace rocket

#endif