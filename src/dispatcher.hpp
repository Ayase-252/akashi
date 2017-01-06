#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "json.hpp"
#include <string>

using std::string;
using nlohmann::json;

typedef void (*handler_function)(const json&);

namespace akashi {
class dispatcher {
public:
  dispatcher(void);
  void set_handler(const std::string&, handler_function);
  bool dispatch(json &);
  json get_last_dispatched_command(void) const;

private:
  json last_dispatched_command;
};
}

#endif
