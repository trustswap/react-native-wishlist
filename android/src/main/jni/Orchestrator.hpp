#pragma once

#include <fbjni/fbjni.h>
#include "MGDIImpl.hpp"

using namespace facebook;

namespace Wishlist {

class Orchestrator : public jni::HybridClass<Orchestrator> {
 public:
  Orchestrator(const std::string &wishlistId, int viewportCarerRef);

  static constexpr auto kJavaDescriptor = "Lcom/wishlist/Orchestrator;";

  static void registerNatives();

 private:
  static jni::local_ref<jhybriddata> initHybrid(
      jni::alias_ref<jclass>,
      std::string wishlistId,
      int viewportCarerRef);

  void renderAsync(
      float width,
      float height,
      float initialOffset,
      int originItem,
      int templatesRef,
      jni::alias_ref<jni::JList<jni::JString>> names,
      std::string inflatorId);

  void didScrollAsync(
      float width,
      float height,
      float contentOffset,
      std::string inflatorId);

 private:
  void handleVSync();

  class Adapter final : public MGPushChildrenListener, public MGVSyncRequester {
   public:
    Adapter(std::function<void()> onRequestVSync);

   private:
    void didPushChildren(std::vector<Item> newWindow) override;
    void requestVSync() override;

    std::function<void()> onRequestVSync_;
  };

  friend HybridBase;

  bool alreadyRendered_;
  std::shared_ptr<MGDIImpl> di_;
  std::shared_ptr<Adapter> adapter_;
  float width_;
  float height_;
  float contentOffset_;
  std::string inflatorId_;
};

} // namespace Wishlist