#ifndef ROCKET_NET_RPC_CHANNEL_H_
#define ROCKET_NET_RPC_CHANNEL_H_

#include <google/protobuf/service.h>
#include "rocket/net/tcp/net_addr.h"

namespace rocket
{
    class RpcChannel : public google::protobuf::RpcChannel
    {
    private:
        NetAddr::s_ptr m_peer_addr{nullptr};
        NetAddr::s_ptr m_local_addr{nullptr};

    public:
        RpcChannel(NetAddr::s_ptr peer_addr);
        ~RpcChannel();
        void CallMethod(const google::protobuf::MethodDescriptor *method,
                        google::protobuf::RpcController *controller, const google::protobuf::Message *request,
                        google::protobuf::Message *response, google::protobuf::Closure *done);
    };

} // namespace rocket

#endif