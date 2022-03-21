#ifndef PROCESSVERIFY_H
#define PROCESSVERIFY_H

#include<istream>
#include "messages/VoiceVerificationMessage.grpc.pb.h"

class ProcessVerify
{
public:
    ProcessVerify();
    ~ProcessVerify();

     void verifyVoice(std::string pathVerify, std::string pathTrained, VoiceVerificationResponseMsg* response);
};

#endif // PROCESSVERIFY_H
