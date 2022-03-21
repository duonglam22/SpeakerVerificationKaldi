// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: VoiceVerificationMessage.proto
#ifndef GRPC_VoiceVerificationMessage_2eproto__INCLUDED
#define GRPC_VoiceVerificationMessage_2eproto__INCLUDED

#include "VoiceVerificationMessage.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

class VerificationMsgService final {
 public:
  static constexpr char const* service_full_name() {
    return "VerificationMsgService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // using for module DataConverter send msg to DataCollection msg   
    virtual ::grpc::Status verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::VoiceVerificationResponseMsg* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>> AsyncverificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>>(AsyncverificationVoiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>> PrepareAsyncverificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>>(PrepareAsyncverificationVoiceRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // using for module DataConverter send msg to DataCollection msg   
      virtual void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>* AsyncverificationVoiceRaw(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::VoiceVerificationResponseMsg>* PrepareAsyncverificationVoiceRaw(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::VoiceVerificationResponseMsg* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>> AsyncverificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>>(AsyncverificationVoiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>> PrepareAsyncverificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>>(PrepareAsyncverificationVoiceRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void verificationVoice(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>* AsyncverificationVoiceRaw(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::VoiceVerificationResponseMsg>* PrepareAsyncverificationVoiceRaw(::grpc::ClientContext* context, const ::VoiceVerificationRequestMsg& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_verificationVoice_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // using for module DataConverter send msg to DataCollection msg   
    virtual ::grpc::Status verificationVoice(::grpc::ServerContext* context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_verificationVoice() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestverificationVoice(::grpc::ServerContext* context, ::VoiceVerificationRequestMsg* request, ::grpc::ServerAsyncResponseWriter< ::VoiceVerificationResponseMsg>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_verificationVoice<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_verificationVoice() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::VoiceVerificationRequestMsg, ::VoiceVerificationResponseMsg>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::VoiceVerificationRequestMsg* request, ::VoiceVerificationResponseMsg* response) { return this->verificationVoice(context, request, response); }));}
    void SetMessageAllocatorFor_verificationVoice(
        ::grpc::experimental::MessageAllocator< ::VoiceVerificationRequestMsg, ::VoiceVerificationResponseMsg>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::VoiceVerificationRequestMsg, ::VoiceVerificationResponseMsg>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* verificationVoice(
      ::grpc::CallbackServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* verificationVoice(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_verificationVoice<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_verificationVoice<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_verificationVoice() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_verificationVoice() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestverificationVoice(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_verificationVoice() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->verificationVoice(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* verificationVoice(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* verificationVoice(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_verificationVoice : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_verificationVoice() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::VoiceVerificationRequestMsg, ::VoiceVerificationResponseMsg>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::VoiceVerificationRequestMsg, ::VoiceVerificationResponseMsg>* streamer) {
                       return this->StreamedverificationVoice(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_verificationVoice() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status verificationVoice(::grpc::ServerContext* /*context*/, const ::VoiceVerificationRequestMsg* /*request*/, ::VoiceVerificationResponseMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedverificationVoice(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::VoiceVerificationRequestMsg,::VoiceVerificationResponseMsg>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_verificationVoice<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_verificationVoice<Service > StreamedService;
};


#endif  // GRPC_VoiceVerificationMessage_2eproto__INCLUDED
