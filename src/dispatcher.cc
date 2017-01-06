#include "dispatcher.hpp"

namespace akashi {
dispatcher::dispatcher(void):
last_dispatched_command("{}"_json) {

}

void
dispatcher::set_handler(const string &command, handler_function pHandler){
  dispatch_table.insert({command, pHandler});
}

bool
dispatcher::dispatch(json &incoming_json){
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
dispatcher::get_last_dispatched_command(void) const{
  return last_dispatched_command;
}
}
