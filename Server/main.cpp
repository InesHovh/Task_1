#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char **argv)
{
    try {
        boost::asio::io_context io_context;

        //create acceptor object that will listen for incoming connections

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1337));

        while(true)
        {
            std::cout << "Accepting connections on port 1337! " << std::endl;
            //create a socket
            tcp::socket socket(io_context);

            //accept a connection on that socket
            acceptor.accept(socket);

            //send the message back to the client 
            std::cout << "Client connectied. Sending messages!" << std::endl;
            std::string message = "Hello, dear client!\n" ;
            boost::system::error_code error;

            boost::asio::write(socket, boost::asio::buffer(message), error);


        } 
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

