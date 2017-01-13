#include "parser.hpp"

namespace akashi {
json
Parser::parse(const string &str){
  return json::parse(str);
}

string
Parser::serialize(const json &json_data) {
  return json_data.dump();
}
}
