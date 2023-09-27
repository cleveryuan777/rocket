#ifndef ROCKET_NET_IO_THREAD_GROUP_H_
#define ROCKET_NET_IO_THREAD_GROUP_H_

#include <vector>
#include "rocket/net/io_thread.h"
#include "rocket/common/log.h"

namespace rocket
{
    class IOThreadGroup
    {
    private:
        size_t m_size{0};
        std::vector<IOThread *> m_io_thread_group;
        int m_index{0};

    public:
        IOThreadGroup(int size);

        ~IOThreadGroup();

        void start();
        void join();

        IOThread *getIOThread();
    };

} // namespace rocket

#endif