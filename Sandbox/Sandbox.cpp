#include "intmsg.h"
#include "strmsg.h"

#include "Client/include.h"

#include <iostream>

int main()
{
    NIO::Common::SerialMessage<MessageTypes>::MessageHeader msg = {
        MessageTypes::SendInt,
        10
    };

    msg.id;

    std::cout << "Hello World!" << std::endl;

    intMsg m1;
    strMsg m2("test");

    return 0;
}