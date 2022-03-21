
#include<bits/stdc++.h>
#include <experimental/filesystem>

#include "processregister.h"
#include "enroll.h"


ProcessRegister::ProcessRegister()
{
    std::cout << "initial ProcessRegister" << std::endl;
}

ProcessRegister::~ProcessRegister() {
    std::cout << "destructor ProcessRegister" << std::endl;
}

void ProcessRegister::registerVoice(int requestType, std::string path, VoiceRegisterResponseMsg *responseMsg) {
    std::string spkid =  ""; // speaker id
    std::string voiceDir = ""; // speech waveform
    std::string fileName = "";
    responseMsg->set_errorcode(94);
    responseMsg->set_additionalinfo("unknow error");
    // /home/dnlam/data/examples/example_data/enroll/30/30-Mark_Zuckerberg_20s_2.wav
    std::vector<std::string> vText = getTokens(path, '/');

    int lenth = vText.size();
    for(int i = 0; i < lenth - 1; i++) {
        std::cout << vText.at(i) << " ";
        voiceDir += vText.at(i);
        if(i != lenth - 2) {
            voiceDir += "/";
        }
    }
    std::cout << std::endl;

    if(lenth > 2) {
        fileName = vText.at(lenth - 1);
        spkid = vText.at(lenth - 2);
    }

    if(requestType == 3) //remove trained file
    {
        std::string folderIv = voiceDir + "/iv/*";
        removeFolder(folderIv);
        std::cout << "remove folder : " << folderIv << std::endl;
        responseMsg->set_errorcode(0);
        responseMsg->set_additionalinfo("remove trained file success!");
        return;
    }

    std::cout << spkid << ", " << fileName << ", " << voiceDir << std::endl;
    Enroll* enroll = new Enroll();
    try {
        enroll->enrollVoice(spkid, voiceDir, fileName, requestType, responseMsg);
    } catch (std::exception& ex) {
        std::cout << "occurs exceptions: " <<  ex.what() << std::endl;
    }

    if(enroll != NULL)
    {
        delete enroll;
        enroll = NULL;
    }
}

//void ProcessRegister::registerVoice(std::string path) {
//    std::string spkid =  ""; // speaker id
//    std::string voiceDir = "/"; // speech waveform
//    std::string fileName = "";
//    // /home/dnlam/data/examples/example_data/enroll/30/30-Mark_Zuckerberg_20s_2.wav
//    std::vector<std::string> vText = getTokens(path, '/');

//    int lenth = vText.size();
//    for(int i = 0; i < lenth - 1; i++) {
//        std::cout << vText.at(i) << " ";
//        voiceDir += vText.at(i);
//        if(i != lenth - 2) {
//            voiceDir += "/";
//        }
//    }
//    std::cout << std::endl;

//    if(lenth > 2) {
//        fileName = vText.at(lenth - 1);
//        spkid = vText.at(lenth - 2);
//    }

//    std::cout << spkid << ", " << fileName << ", " << voiceDir << std::endl;
//    Enroll* enroll = new Enroll();
//    enroll->enrollVoice(spkid, voiceDir, fileName);
//}

std::vector<std::string> ProcessRegister::getTokens(std::string text, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream streamText(text);
    std::string item;

    while(getline(streamText, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

bool ProcessRegister::removeFolder(std::string path)
{
    try {
        std::experimental::filesystem::remove(path);
    } catch (std::exception& ex) {
        std::cout << "occurs exception when create folder: " << std::endl;
    }
}

