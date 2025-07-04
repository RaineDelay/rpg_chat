#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#include "common.h"

int main()
{
    boost::system::error_code ec;
    std::cout << "Hello World!" << std::endl;

    boost::asio::io_context context;
    boost::asio::io_context::work idle(context);
    std::thread context_thread = std::thread([&](){ context.run(); });


    return 0;
}