#include <iostream>
//#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"


int main()
{
    httplib::Client Client("http://cpp-httplib-server.yhirose.repl.co");
    auto res = Client.Get("/");
    res->status;
    res->body;

    std::cout << res->status << '\n';
    std::cout << res->body << '\n';

    std::cin.get();
}