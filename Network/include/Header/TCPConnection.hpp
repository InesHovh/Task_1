#pragma once

#include <iostream>
#include <boost/asio.hpp>

namespace MyProject{
    using boost::asio::ip::tcp;

    class TCPConnection
    {
    private:
        tcp::socket m_socket;
        std::string m_message { "Hello, dear client!\n" };
    private:
        TCPConnection(boost::asio::io_context &io_context);
    public:
        tcp::socket &Socket(){
            return m_socket;
        }

        void Start();
    };
       
}