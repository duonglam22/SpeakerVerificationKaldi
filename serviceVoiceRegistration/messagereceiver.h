#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H

#include<iostream>
#include "processregister.h"

class MessageReceiver
{
public:
    MessageReceiver();
    ~MessageReceiver();

    void runServer();

private:
    ProcessRegister* processRegister;
};

#endif // MESSAGERECEIVER_H
