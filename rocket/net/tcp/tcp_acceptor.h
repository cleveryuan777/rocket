#ifndef ROCKET_NET_TCP_TCPACCEPTOR_H_
#define ROCKET_NET_TCP_TCPACCEPTOR_H_

#include "rocket/net/tcp/net_addr.h"
#include <memory>

namespace rocket
{
    class TcpAcceptor
    {
    private:
        /* data */
        NetAddr::s_ptr m_local_addr;
        int m_family{-1};
        int m_listenfd{-1};

    public:
        typedef std::shared_ptr<TcpAcceptor> s_ptr;
        TcpAcceptor(NetAddr::s_ptr local_addr);
        ~TcpAcceptor();

        int accept();

        int getListenFd();
    };

} // namespace rocket

#endif