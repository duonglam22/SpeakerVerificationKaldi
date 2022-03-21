// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: VoiceRegisterMessage.proto

#include "VoiceRegisterMessage.pb.h"
#include "VoiceRegisterMessage.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* RegisterMsgService_method_names[] = {
  "/RegisterMsgService/registerVoice",
};

std::unique_ptr< RegisterMsgService::Stub> RegisterMsgService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< RegisterMsgService::Stub> stub(new RegisterMsgService::Stub(channel, options));
  return stub;
}

RegisterMsgService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_registerVoice_(RegisterMsgService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status RegisterMsgService::Stub::registerVoice(::grpc::ClientContext* context, const ::VoiceRegisterRequestMsg& request, ::VoiceRegisterResponseMsg* response) {
  return ::grpc::internal::BlockingUnaryCall< ::VoiceRegisterRequestMsg, ::VoiceRegisterResponseMsg, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_registerVoice_, context, request, response);
}

void RegisterMsgService::Stub::experimental_async::registerVoice(::grpc::ClientContext* context, const ::VoiceRegisterRequestMsg* request, ::VoiceRegisterResponseMsg* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::VoiceRegisterRequestMsg, ::VoiceRegisterResponseMsg, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_registerVoice_, context, request, response, std::move(f));
}

void RegisterMsgService::Stub::experimental_async::registerVoice(::grpc::ClientContext* context, const ::VoiceRegisterRequestMsg* request, ::VoiceRegisterResponseMsg* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_registerVoice_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::VoiceRegisterResponseMsg>* RegisterMsgService::Stub::PrepareAsyncregisterVoiceRaw(::grpc::ClientContext* context, const ::VoiceRegisterRequestMsg& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::VoiceRegisterResponseMsg, ::VoiceRegisterRequestMsg, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_registerVoice_, context, request);
}

::grpc::ClientAsyncResponseReader< ::VoiceRegisterResponseMsg>* RegisterMsgService::Stub::AsyncregisterVoiceRaw(::grpc::ClientContext* context, const ::VoiceRegisterRequestMsg& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncregisterVoiceRaw(context, request, cq);
  result->StartCall();
  return result;
}

RegisterMsgService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterMsgService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterMsgService::Service, ::VoiceRegisterRequestMsg, ::VoiceRegisterResponseMsg, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterMsgService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::VoiceRegisterRequestMsg* req,
             ::VoiceRegisterResponseMsg* resp) {
               return service->registerVoice(ctx, req, resp);
             }, this)));
}

RegisterMsgService::Service::~Service() {
}

::grpc::Status RegisterMsgService::Service::registerVoice(::grpc::ServerContext* context, const ::VoiceRegisterRequestMsg* request, ::VoiceRegisterResponseMsg* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


