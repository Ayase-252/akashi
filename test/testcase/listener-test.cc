#include "catch.hpp"
#include "listener.hpp"

using namespace akashi;

TEST_CASE("Listener should be configured correctly by constructor.", "[Listener]") {
  SECTION("Listener should listen to specified port.") {
    auto listener = Listener(8024);
  }
}
