#include "rocket/net/tcp/tcp_acceptor.h"
#include "rocket/common/log.h"
#include <assert.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>

namespace rocket
{
    TcpAcceptor::TcpAcceptor(NetAddr::s_ptr local_addr) : m_local_addr(local_addr)
    {
        if (!m_local_addr->checkVaild())
        {
            ERRORLOG("invalid local addr %s", m_local_addr->toString().c_str());
            exit(0);
        }
        m_family = m_local_addr->getFamily();

        m_listenfd = socket(m_family, SOCK_STREAM, 0);

        if (m_listenfd < 0)
        {
            ERRORLOG("invalid listenfd %d", m_listenfd);
            exit(0);
        }
        int val = 1;
        if (setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) != 0)
        {
            ERRORLOG("setsockopt SO_REUSEADDR error, errno = %d, error = %s", strerror(errno));
        }

        socklen_t len = m_local_addr->getSockLen();
        if (bind(m_listenfd, m_local_addr->getSockAddr(), len) != 0)
        {
            ERRORLOG("bind error, errno = %d, error = %s", strerror(errno));
            exit(0);
        }

        if (listen(m_listenfd, 1000) != 0)
        {
            ERRORLOG("listen error, errno = %d, error = %s", strerror(errno));
            exit(0);
        }
    }

    TcpAcceptor::~TcpAcceptor()
    {
    }

    int TcpAcceptor::getListenFd()
    {
        return m_listenfd;
    }

    int TcpAcceptor::accept()
    {
        if (m_family == AF_INET)
        {
            sockaddr_in clien_addr;
            memset(&clien_addr, 0, sizeof(clien_addr));
            socklen_t clien_addr_len = sizeof(clien_addr);

            int clien_fd = ::accept(m_listenfd, reinterpret_cast<sockaddr *>(&clien_addr), &clien_addr_len);
            if (clien_fd < 0)
            {
                ERRORLOG("accept error, errno = %d, error = %s", strerror(errno));
            }
            IPNetAddr peer_addr(clien_addr);
            INFOLOG("A client have accpeted succ, peer addr [%s]", peer_addr.toString().c_str());
            return clien_fd;
        }
        else
        {
            // ....
            return -1;
        }
    }

} // namespace rocket
