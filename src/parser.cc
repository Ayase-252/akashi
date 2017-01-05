#include "parser.hpp"

namespace akashi {
json
parser::parse(const string &str){
  return json::parse(str);
}

string
parser::serialize(const json &json_data) {
  return json_data.dump();
}
}
