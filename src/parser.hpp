#ifndef PARSER_HPP
#define PARSER_HPP

#include "json.hpp"

using std::string;
using nlohmann::json;

namespace akashi {
  class parser {
  public:
    static json parse(string str);
  };
}

#endif
