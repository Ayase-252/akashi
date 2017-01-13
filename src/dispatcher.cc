#include "dispatcher.hpp"

namespace akashi {
Dispatcher::Dispatcher(void):
last_dispatched_command("{}"_json) {

}

void
Dispatcher::set_handler(const string &command, handler_function pHandler){
  dispatch_table.insert({command, pHandler});
}

bool
Dispatcher::dispatch(json &incoming_json){
  // Command is not in dispatch table.
  string command = incoming_json["command"];
  if(dispatch_table.find(command) == dispatch_table.end()) {
    return false;
  }
  dispatch_table[command](incoming_json);
  last_dispatched_command = incoming_json;
  return true;
}

json
Dispatcher::get_last_dispatched_command(void) const{
  return last_dispatched_command;
}
}
