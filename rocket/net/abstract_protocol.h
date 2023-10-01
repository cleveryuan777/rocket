#ifndef ROCKET_NET_ABSTRACT_PROTOCOL_H_
#define ROCKET_NET_ABSTRACT_PROTOCOL_H_

#include <memory>

namespace rocket
{
    class AbstractProtocol
    {
    private:
        /* data */
    public:
        typedef std::shared_ptr<AbstractProtocol> s_ptr;

    };

} // namespace rocket

#endif