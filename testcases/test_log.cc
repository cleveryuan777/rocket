#include "rocket/common/log.h"
#include "rocket/common/config.h"
#include <pthread.h>

void *func(void *)
{
    int i = 20;
    while (i--)
    {
        DEBUGLOG("debug this is thread in   %s", "func");
        INFOLOG("info this is thread in   %s", "func");
    }
    return NULL;
}

int main()
{
    rocket::Config::SetGlobalConfig("../conf/rocket.xml");
    rocket::Logger::InitGlobalLogger();

    pthread_t thread;
    pthread_create(&thread, NULL, &func, NULL);

    int i = 20;
    while (i--)
    {
        DEBUGLOG("test debug %s", "11");
        INFOLOG("test info  %s", "11");
    }

    pthread_join(thread, NULL);

    return 0;
}