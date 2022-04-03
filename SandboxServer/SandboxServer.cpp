#include "SandboxCommon/include.h"
#include "Common/include.h"

#include <iostream>

NIO_COMMON_IMPLEXTERNS(MessageTypes)

int main()
{
    intMsg::registerMsgType([](intMsg msg)
        {
            std::cout << msg.value << std::endl;
        });

    strMsg::registerMsgType([](strMsg msg)
        {
            std::cout << msg.getValue() << std::endl;
        });

    intMsg m1(1);
    strMsg m2("test");

    NIO::Common::SerialMessage<MessageTypes> m1serial = m1.serialise();
    NIO::Common::SerialMessage<MessageTypes> m2serial = m2.serialise();

    NIO::Common::ISendable<MessageTypes>::deserialise(m1serial);
    NIO::Common::ISendable<MessageTypes>::deserialise(m2serial);

    return 0;
}