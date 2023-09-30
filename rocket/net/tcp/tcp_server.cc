#include "rocket/net/tcp/tcp_server.h"
#include "rocket/common/log.h"
#include <functional>

namespace rocket
{
    TcpServer::TcpServer(NetAddr::s_ptr local_addr) : m_local_addr(local_addr)
    {
        init();

        INFOLOG("rocket TcpServer listen succ on [%s]", m_local_addr->toString().c_str());
    }

    TcpServer::~TcpServer()
    {
        if (m_main_event_loop)
        {
            delete m_main_event_loop;
            m_main_event_loop = nullptr;
        }

        if (m_io_thread_group)
        {
            delete m_io_thread_group;
            m_io_thread_group = nullptr;
        }
    }

    void TcpServer::start()
    {
        m_io_thread_group->start();
        m_main_event_loop->loop();
    }

    void TcpServer::init()
    {
        m_acceptor = std::make_shared<TcpAcceptor>(m_local_addr);
        m_main_event_loop = EventLoop::GetCurrentEventLoop();
        m_io_thread_group = new IOThreadGroup(2);

        m_listen_fd_event = new FdEvent(m_acceptor->getListenFd());
        m_listen_fd_event->listen(FdEvent::IN_EVENT, std::bind(&TcpServer::onAccept, this));
        m_main_event_loop->addEpollEvent(m_listen_fd_event);
    }

    void TcpServer::onAccept()
    {
        int clien_fd = m_acceptor->accept();
        // FdEvent clien_fd_event(clien_fd);
        m_clien_count++;
        // TODO: 把clien_fd 添加到任意 IO 线程里面
        // m_io_thread_group->getIOThread()->getEventLoop()->addEpollEvent();

        INFOLOG("TcpServer succ get client , fd = %d", clien_fd);
    }
} // namespace rocket
