#ifndef ROCKET_NET_TCP_TCPCLIENT_H_
#define ROCKET_NET_TCP_TCPCLIENT_H_

#include <memory>
#include "rocket/net/tcp/net_addr.h"
#include "rocket/net/eventloop.h"
#include "rocket/common/log.h"
#include "rocket/net/tcp/tcp_connection.h"
#include "rocket/net/coder/abstract_protocol.h"
#include "rocket/net/timer_event.h"

namespace rocket
{
    class TcpClient
    {
    private:
        NetAddr::s_ptr m_peer_addr;
        NetAddr::s_ptr m_local_addr;
        EventLoop *m_event_loop{nullptr};
        int m_fd{-1};
        FdEvent *m_fd_event{nullptr};
        TcpConnection::s_ptr m_connection;

        int m_connect_error_code{0};
        std::string m_connect_error_info;

    public:
        typedef std::shared_ptr<TcpClient> s_ptr;
        TcpClient(NetAddr::s_ptr peer_addr);
        ~TcpClient();

        // 异步的进行 connect
        // 如果connect完成，done 会被执行
        void connect(std::function<void()> done);

        // 异步的发送message
        // 如果发送message 成功，会调用done，函数的入参就是message对象
        void writeMessage(AbstractProtocol::s_ptr message, std::function<void(AbstractProtocol::s_ptr)> done);

        // 异步的读取message
        // 如果读取message 成功，会调用done，函数的入参就是message对象
        void readMessage(const std::string &msg_id, std::function<void(AbstractProtocol::s_ptr)> done);

        void stop();

        int getConnectErrorCode();
        std::string getConnectErrorInfo();

        NetAddr::s_ptr getPeerAddr();
        NetAddr::s_ptr getLocalAddr();

        void initLocalAddr();

        void addTimerEvent(TimerEvent::s_ptr timer_event);
    };

} // namespace rocket

#endif