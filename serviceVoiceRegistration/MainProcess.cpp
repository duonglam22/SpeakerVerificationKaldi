#include "messagereceiver.h"
#include "processregister.h"

int main() {
    std::cout << "starting Voice Register application, have a nice day!" << std::endl;

//    ProcessRegister* process = new ProcessRegister();
//    process->registerVoice("/home/dnlam/data/examples/example_data/enroll/30/30-Mark_Zuckerberg_20s_2.wav");

    MessageReceiver* receiver = new MessageReceiver();
    receiver->runServer();

    return 0;
}
