
#include<grpc++/grpc++.h>

#include "messagereceiver.h"
#include "messages/VoiceRegisterMessage.grpc.pb.h"
#include "processregister.h"

class VoiceRegisterMsgServiceImpl final : public RegisterMsgService::Service {
    grpc::Status registerVoice(grpc::ServerContext *context, const VoiceRegisterRequestMsg *request, VoiceRegisterResponseMsg *response) override
    {
        std::cout << "received new register request " << std::endl;
        std::string pathFile = request->path_file();
        int typeRequest = request->type();
        ProcessRegister* process = new ProcessRegister();
        process->registerVoice(typeRequest, pathFile, response);
//		Event *event = new Event();
//		event->sourceName = request->source_name();
//		event->seqId = request->seqid();
//		event->data = request->data();
//		Communication::getInstance()->receivedEvent(event);
        if(process != NULL)
        {
            delete process;
            process = NULL;
        }
        return grpc::Status::OK;
    }
};

MessageReceiver::MessageReceiver()
{
    std::cout << "initial MessageReceiver" << std::endl;
    processRegister = new ProcessRegister();
}

MessageReceiver::~MessageReceiver() {
    std::cout << "desstructor MessageReceiver";
}

void MessageReceiver::runServer() {
    std::string serverPort = "0.0.0.0:38890";

//	std::string server_address("0.0.0.0:38890");
    VoiceRegisterMsgServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(serverPort, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout <<"start listening on " << serverPort << std::endl;
    server->Wait();
    std::cout << "stop gRpc server" << std::endl;
}
