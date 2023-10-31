#pragma once

#include <iostream>
#include <boost/asio.hpp>

namespace MyProject{
    enum class IPV{
        v4,
        v6
    };

    class TCPServer
    {
        private:
            void StartAccept();
        private:
            IPV m_ipv;
            int m_port;

            boost::asio::io_context m_io_context;
            boost::asio::ip::tcp::acceptor m_acceptor;
        public:
            TCPServer(IPV ipv, int port);
            ~TCPServer() {};
            int run();
    };
};