#include <assert.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <memory>
#include <unistd.h>
#include <google/protobuf/service.h>
#include "rocket/common/log.h"
#include "rocket/common/config.h"
#include "rocket/common/log.h"
#include "rocket/net/tcp/net_addr.h"
#include "rocket/net/tcp/tcp_server.h"
#include "rocket/net/coder/string_coder.h"
#include "rocket/net/coder/abstract_protocol.h"
#include "rocket/net/coder/tinypb_coder.h"
#include "rocket/net/coder/tinypb_protocol.h"
#include "order.pb.h"
#include "rocket/net/rpc/rpc_dispatcher.h"

class OrderImpl : public Order
{
public:
    void makeOrder(google::protobuf::RpcController *controller,
                   const ::makeOrderRequest *request,
                   ::makeOrderResponse *response,
                   ::google::protobuf::Closure *done)
    {
        APPDEBUGLOG("start sleep 5s");
        sleep(5);
        APPDEBUGLOG("end sleep 5s");
        if (request->price() < 10)
        {
            response->set_ret_code(-1);
            response->set_res_info("short balance");
            return;
        }
        response->set_order_id("20231005");
        APPDEBUGLOG("call makeOrder success");
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Start test_rpc_server error, argc not 2!\n");
        printf("like this\n");
        printf("like this ../conf/rocket.xml\n");
        return 0;
    }
    rocket::Config::SetGlobalConfig(argv[1]);
    rocket::Logger::InitGlobalLogger();

    std::shared_ptr<OrderImpl> order_service = std::make_shared<OrderImpl>();
    rocket::RpcDispatcher::GetDispatcher()->registerService(order_service);

    rocket::IPNetAddr::s_ptr addr = std::make_shared<rocket::IPNetAddr>("127.0.0.1", rocket::Config::GetGlobalConfig()->m_port);

    rocket::TcpServer tcp_server(addr);

    tcp_server.start();

    return 0;
}
