#include "../include/Header/TCPConnection.hpp"

namespace MyProject{
    TCPConnection::TCPConnection(boost::asio::io_context &io_context) : m_socket(io_context){
        
    }

    void TCPConnection::Start(){

    }

}