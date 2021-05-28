/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#pragma once

#include <exception>
#include <memory>

#include <mcrouter/lib/network/RpcStatsContext.h>
#include <mcrouter/lib/network/ThriftTransport.h>
#include <mcrouter/McrouterFiberContext.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/TTransportException.h>
#include <thrift/lib/cpp2/async/RequestChannel.h>

#include "mcrouter/lib/carbon/test/gen/gen-cpp2/CarbonThriftTestAsyncClient.h"

namespace facebook {
namespace memcache {

template <>
class ThriftTransportMethods<carbon::test::CarbonThriftTestRouterInfo> : public ThriftTransportUtil {
 public:
  ThriftTransportMethods() = default;
  virtual ~ThriftTransportMethods() override = default;

folly::Try<apache::thrift::RpcResponseComplete<carbon::test::CustomReply>> sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const carbon::test::CustomRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  auto reply = thriftClient->sync_complete_customRequest(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
  return reply;
}

folly::Try<apache::thrift::RpcResponseComplete<carbon::test::DummyThriftReply>> sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const carbon::test::DummyThriftRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  auto reply = thriftClient->sync_complete_thrift_test(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
  return reply;
}

folly::Try<apache::thrift::RpcResponseComplete<carbon::test::ThriftTestReply>> sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const carbon::test::ThriftTestRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  auto reply = thriftClient->sync_complete_test(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
  return reply;
}

folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>> sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const McVersionRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  auto reply = thriftClient->sync_complete_mcVersion(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
  return reply;
}

};

template <>
class ThriftTransport<carbon::test::CarbonThriftTestRouterInfo> : public ThriftTransportMethods<carbon::test::CarbonThriftTestRouterInfo>,
                                       public ThriftTransportBase {
 public:
  ThriftTransport(folly::EventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase, std::move(options)) {}
  ThriftTransport(folly::VirtualEventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase.getEventBase(), std::move(options)) {}
  ~ThriftTransport() override {
    resetClient();
  }

  void setFlushList(FlushList* flushList) override final {
    flushList_ = flushList;
    if (thriftClient_) {
      auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
          thriftClient_->getChannel());
      channel->setFlushList(flushList_);
    }
  }

  carbon::test::CustomReply sendSync(
      const carbon::test::CustomRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        return sendSyncHelper(thriftClient, request, rpcOptions, rpcStatsContext);
      } else {
        return folly::Try<apache::thrift::RpcResponseComplete<carbon::test::CustomReply>>(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
    });
  }

  carbon::test::DummyThriftReply sendSync(
      const carbon::test::DummyThriftRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        return sendSyncHelper(thriftClient, request, rpcOptions, rpcStatsContext);
      } else {
        return folly::Try<apache::thrift::RpcResponseComplete<carbon::test::DummyThriftReply>>(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
    });
  }

  carbon::test::ThriftTestReply sendSync(
      const carbon::test::ThriftTestRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        return sendSyncHelper(thriftClient, request, rpcOptions, rpcStatsContext);
      } else {
        return folly::Try<apache::thrift::RpcResponseComplete<carbon::test::ThriftTestReply>>(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
    });
  }

  McVersionReply sendSync(
      const McVersionRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        return sendSyncHelper(thriftClient, request, rpcOptions, rpcStatsContext);
      } else {
        return folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>>(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
    });
  }

 private:
  std::optional<carbon::test::thrift::CarbonThriftTestAsyncClient> thriftClient_;
  FlushList* flushList_{nullptr};

  carbon::test::thrift::CarbonThriftTestAsyncClient* getThriftClient() {
    if (UNLIKELY(!thriftClient_)) {
      thriftClient_ = createThriftClient<carbon::test::thrift::CarbonThriftTestAsyncClient>();
      if (flushList_) {
        auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
            thriftClient_->getChannel());
        channel->setFlushList(flushList_);
      }
    }
    return thriftClient_.has_value() ? &thriftClient_.value() : nullptr;
  }

  void resetClient() override final {
    if (thriftClient_) {
      if (auto channel = thriftClient_->getChannel()) {
        // Reset the callback to avoid the following cycle:
        //  ~ThriftAsyncClient() -> ~RocketClientChannel() ->
        //  channelClosed() -> ~ThriftAsyncClient()
        channel->setCloseCallback(nullptr);
      }
      thriftClient_.reset();
    }
  }
};

} // namespace memcache
} // namespace facebook