#include "messagereceiver.h"
#include "processverify.h"
#include<iostream>

int main() {
    std::cout << "starting Voice Register application, have a nice day!" << std::endl;

//    ProcessVerify* process = new ProcessVerify();
//    std::string pathTrain = "/home/dnlam/data/examples/example_data/enroll/30/iv";
//    std::string pathVerify = "/home/dnlam/data/examples/example_data/enroll/30/30-Mark_Zuckerberg_20s_2.wav";
//    process->verifyVoice(pathVerify, pathTrain);

    MessageReceiver* receiver = new MessageReceiver();
    receiver->runServer();

    return 0;
}
