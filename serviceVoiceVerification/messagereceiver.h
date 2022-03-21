#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H

#include "processverify.h"

class MessageReceiver
{
public:
    MessageReceiver();
    ~MessageReceiver();

    void runServer();

private:
    ProcessVerify* processVerify;
};

#endif // MESSAGERECEIVER_H
