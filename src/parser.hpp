#ifndef PARSER_HPP
#define PARSER_HPP

#include "json.hpp"
#include <string>

using std::string;
using nlohmann::json;

namespace akashi {
class Parser {
public:
  static json parse(const string&);
  static string serialize(const json&);
};
}

#endif
