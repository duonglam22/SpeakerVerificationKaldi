#include<grpc++/grpc++.h>
#include "messagereceiver.h"
#include "messages/VoiceVerificationMessage.grpc.pb.h"

class VerificationMsgServiceImpl final : public VerificationMsgService::Service {
    grpc::Status verificationVoice(grpc::ServerContext *context, const VoiceVerificationRequestMsg *request, VoiceVerificationResponseMsg *response) override
    {
        std::cout << "received new register request " << std::endl;
        std::string pathFile = request->path_file_verify();
        std::string pathTrain = request->path_file_trained();
        ProcessVerify* process = new ProcessVerify();
        process->verifyVoice(pathFile, pathTrain, response);

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
    processVerify = new ProcessVerify();
}

MessageReceiver::~MessageReceiver() {
    std::cout << "desstructor MessageReceiver";
}

void MessageReceiver::runServer() {
    std::string serverPort = "0.0.0.0:38891";

//	std::string server_address("0.0.0.0:38890");
    VerificationMsgServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(serverPort, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout <<"start listening on " << serverPort << std::endl;
    server->Wait();
    std::cout << "stop gRpc server" << std::endl;
}
