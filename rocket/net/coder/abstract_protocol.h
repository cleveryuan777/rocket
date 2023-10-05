#ifndef ROCKET_NET_ABSTRACT_PROTOCOL_H_
#define ROCKET_NET_ABSTRACT_PROTOCOL_H_

#include <memory>
#include "rocket/net/tcp/tcp_buffer.h"

namespace rocket
{
    struct AbstractProtocol : public std::enable_shared_from_this<AbstractProtocol>
    {
    public:
        std::string m_msg_id; // 请求号，唯一标识一个请求或响应

    public:
        typedef std::shared_ptr<AbstractProtocol> s_ptr;
        virtual ~AbstractProtocol() {}
    };

} // namespace rocket

#endif