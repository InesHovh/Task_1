#include "../include/Header/TCPServer.hpp"
#include <boost/assert.hpp>

namespace MyProject{
    using boost::asio::ip::tcp;
    TCPServer::TCPServer(IPV ipv, int port): m_ipv(ipv), m_port(port), 
        m_acceptor(m_io_context, tcp::endpoint(ipv == IPV::v4 ? tcp::v4() : tcp::v6(), m_port)) {

    }

    int TCPServer::run() {
        //run our io_context
        try
        {
            StartAccept();
            m_io_context.run(); //blocking method 
        } catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
        return 0;
    }

    void TCPServer::StartAccept(){
        //create a connection

        //asynchronosly accept the connection
    }

}