#ifndef PROCESSREGISTER_H
#define PROCESSREGISTER_H

#include "messages/VoiceRegisterMessage.grpc.pb.h"
#include <iostream>

class ProcessRegister
{
public:
    ProcessRegister();
    ~ProcessRegister();

    void registerVoice(int type, std::string path, VoiceRegisterResponseMsg* reponse);
//    void registerVoice(std::string path);
    bool removeFolder(std::string path);

    std::vector<std::string> getTokens(std::string text, char delimiter);
};

#endif // PROCESSREGISTER_H
