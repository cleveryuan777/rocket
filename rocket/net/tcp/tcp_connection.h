#ifndef ROCKET_NET_TCP_TCPCONNECTION_H_
#define ROCKET_NET_TCP_TCPCONNECTION_H_

#include "rocket/net/tcp/net_addr.h"
#include "rocket/net/tcp/tcp_buffer.h"
#include "rocket/net/io_thread.h"
#include <memory>

namespace rocket
{

    enum TcpState
    {
        NotConnected = 1,
        Connected = 2,
        HalfClosing = 3,
        Closed = 4,
    };

    class TcpConnection
    {
    public:
        typedef std::shared_ptr<TcpConnection> s_ptr;

    private:
        IOThread *m_io_thread{nullptr}; // 代表持有该连接的 IO 线程
        NetAddr::s_ptr m_local_addr;
        NetAddr::s_ptr m_peer_addr;

        TcpBuffer::s_ptr m_in_buffer;  // 接收缓冲区
        TcpBuffer::s_ptr m_out_buffer; // 发送缓冲区

        FdEvent *m_fd_event{nullptr};

        TcpState m_state;
        int m_fd{0};

    public:
        TcpConnection(IOThread *io_thread, int fd, int buffer_size, NetAddr::s_ptr peer_addr);
        ~TcpConnection();

        void setState(const TcpState state);

        TcpState getState();

        void clear();
        // 服务器主动关闭连接
        void shutdown();

        void onRead();

        void excute();

        void onWrite();
    };

} // namespace rocket

#endif