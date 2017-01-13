#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "json.hpp"
#include "dispatcher.hpp"

using namespace akashi;

void test_validator(const json &incoming_json) {
}

TEST_CASE("Dispatcher should respond to incoming message based on register handler",
          "[Dispatcher]") {
  Dispatcher message_Dispatcher = Dispatcher();
  message_Dispatcher.set_handler("test", &test_validator);

  SECTION("Respond to registered command") {
    json json_data = {
      {"command", "test"},
      {"args", {1, 2}}
    };
    REQUIRE(message_Dispatcher.dispatch(json_data));
    auto last_dispatched = message_Dispatcher.get_last_dispatched_command();
    REQUIRE(last_dispatched["args"][0] == 1);
    REQUIRE(last_dispatched["args"][1] == 2);
  }

  SECTION("Do not respond to unregistered command") {
    json unregistered_json = {
      {"command", "whatever"},
      {"args", {1, 2, 3}}
    };
    REQUIRE(!message_Dispatcher.dispatch(unregistered_json));
  }
}
