#include <iostream>
#include <array>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char **argv)
{
    try
    {
        boost::asio::io_context io_context;

        //create a tcp resolver, which is equivalent tsp acceptor
        tcp::resolver resolver{ io_context };

        //get a list of endpoints for our resolver to connect to
        //tcp::resolver::results_type 
        auto endpoints = resolver.resolve("127.0.0.1", "1337");

        //create a socket
        tcp::socket socket{ io_context };
        //connect with our socket
        boost::asio::connect(socket, endpoints);

        while(true)
        {
            //Listen for messages
            std::array<char, 128> buf{};
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof){
                //we have successfully received clean shutdown, cut the connection
                break;
            }else if(error) {
                throw boost::system::system_error(error);
            }
            std::cout.write(buf.data(), len);
        } 
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }
    
}