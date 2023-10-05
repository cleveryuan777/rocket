#ifndef ROCKET_NET_RPC_CLOSURE_H_
#define ROCKET_NET_RPC_CLOSURE_H_

#include <google/protobuf/stubs/callback.h>

#include <functional>

namespace rocket
{
    class RpcClosure : public google::protobuf::Closure
    {
    private:
        std::function<void()> m_cb{nullptr};

    public:
        RpcClosure(/* args */);
        ~RpcClosure();
        void Run() override
        {
            if (m_cb != nullptr)
            {
                m_cb();
            }
        }
    };

} // namespace rocket

#endif