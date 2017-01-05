#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "parser.hpp"
#include "json.hpp"

using namespace akashi;

TEST_CASE("Parser should parse JSON string into JSON object", "[parser]") {
    SECTION("JSON Parse test 1") {
      auto json_to_test = "{\"command\": \"Test Command\", \"args\": [\"1\", \"2\"]}";
      auto result =  parser::parse(json_to_test);
      REQUIRE(result["command"] == "Test Command");
      REQUIRE(result["args"][0] == "1");
      REQUIRE(result["args"][1] == "2");
    }
}

TEST_CASE("Parser should convert a JSON object into a standard JSON string",
"[Parser]") {
  SECTION("JSON Serialize Test 1") {
    json json_data = {
      {"command", "Test Command"},
      {"args", {"1", "2"}}
    };
    auto result = parser::serialize(json_data);
    REQUIRE(result.find("\"command\":\"Test Command\"") != string::npos);
    REQUIRE(result.find("\"args\":[\"1\",\"2\"]") != string::npos);
  }
}
