#include "processverify.h"
#include "identifySpeaker.h"

ProcessVerify::ProcessVerify()
{
     std::cout << "initial ProcessVerify object!" << std::endl;
}


ProcessVerify::~ProcessVerify()
{
    std::cout << "destructor ProcessVerify object!" << std::endl;
}

void ProcessVerify::verifyVoice(string pathVerify, string pathTrained, VoiceVerificationResponseMsg* response)
{
    IdentifySpeaker *iden = new IdentifySpeaker();
    iden->identify(pathVerify, pathTrained, response);
    if(iden != NULL)
    {
        delete iden;
        iden = NULL;
    }
}
