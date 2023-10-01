#ifndef ROCKET_NET_CODER_TINYPB_CODER_H_
#define ROCKET_NET_CODER_TINYPB_CODER_H_

#include "rocket/net/coder/abstract_coder.h"
#include "rocket/net/coder/tinypb_protocol.h"

namespace rocket
{
    class TinyPBCoder : public AbstractCoder
    {
    private:
        /* data */
    public:
        void encode(std::vector<AbstractProtocol::s_ptr> &messages, TcpBuffer::s_ptr out_buffer);
        // 将buffer里面的字节流转换成message对象
        void decode(std::vector<AbstractProtocol::s_ptr> &out_messages, TcpBuffer::s_ptr buffer);
        ~TinyPBCoder() {}

    private:
        const char *encodeTinyPB(std::shared_ptr<TinyPBProtocol> message, int &len);
    };

} // namespace rocket

#endif