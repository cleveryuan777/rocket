#ifndef ROCKET_NET_TCP_TCPSERVER_H_
#define ROCKET_NET_TCP_TCPSERVER_H_

#include "rocket/net/tcp/tcp_acceptor.h"
#include "rocket/net/tcp/net_addr.h"
#include "rocket/net/eventloop.h"
#include "rocket/net/io_thread_group.h"

namespace rocket
{
    class TcpServer
    {
    private:
        /* data */
        TcpAcceptor::s_ptr m_acceptor;
        NetAddr::s_ptr m_local_addr;

        EventLoop *m_main_event_loop{nullptr};

        IOThreadGroup *m_io_thread_group{nullptr};

        FdEvent *m_listen_fd_event;

        int m_clien_count{0};

    public:
        TcpServer(NetAddr::s_ptr local_addr);
        ~TcpServer();

        void start();

    private:
        void init();

        // 当有新客户端连接之后执行
        void onAccept();
    };

} // namespace rocket

#endif