#ifndef ROCKET_NET_TCP_TCPBUFFER_H_
#define ROCKET_NET_TCP_TCPBUFFER_H_

#include <vector>
#include <memory>

namespace rocket
{
    class TcpBuffer
    {
    private:
        int m_read_index{0};
        int m_write_index{0};
        int m_size{0};

    public:
        std::vector<char> m_buffer;

    public:
        typedef std::shared_ptr<TcpBuffer> s_ptr;

        TcpBuffer(int size);
        ~TcpBuffer();

        // 返回可读字节数
        int readAble();

        // 返回可写字节数
        int writeAble();

        int readIndex();

        int writeIndex();

        void writeToBuffer(const char *buf, int size);

        void readFromBuffer(std::vector<char> &re, int size);

        void resizeBuffer(int new_size);

        void adjustBuffer();

        void moveReadIndex(int size);

        void moveWriteIndex(int size);
    };
} // namespace rocket

#endif