#ifndef ROCKET_NET_ABSTRACT_CCODER_H_
#define ROCKET_NET_ABSTRACT_CCODER_H_

#include <vector>
#include "rocket/net/tcp/tcp_buffer.h"
#include "rocket/net/coder/abstract_protocol.h"

namespace rocket
{
    class AbstractCoder
    {
    private:
        /* data */
    public:
        // typedef std::shared_ptr<AbstractCoder> s_ptr;
        // 将message对象转化成字节流，写入到buffer
        virtual void encode(std::vector<AbstractProtocol::s_ptr> &messages, TcpBuffer::s_ptr out_buffer) = 0;
        // 将buffer里面的字节流转换成message对象
        virtual void decode(std::vector<AbstractProtocol::s_ptr> &out_messages, TcpBuffer::s_ptr buffer) = 0;
        virtual ~AbstractCoder() {}
    };

} // namespace rocket

#endif