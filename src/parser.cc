#include "parser.hpp"

namespace akashi {
json
parser::parse(const string &str){
  return json::parse(str);
}

string
parser::serilize(const json &json_data) {
  return json_data.dump();
}
}
