#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "json.hpp"
#include <string>
#include <map>

using std::string;
using std::map;
using nlohmann::json;

typedef void (*handler_function)(const json&);

namespace akashi {
class Dispatcher {
public:
  Dispatcher(void);
  void set_handler(const std::string&, handler_function);
  bool dispatch(json &);
  json get_last_dispatched_command(void) const;

private:
  json last_dispatched_command;
  map<string, handler_function> dispatch_table;
};
}

#endif
