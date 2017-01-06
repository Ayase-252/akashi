#include "dispatcher.hpp"

namespace akashi {
dispatcher::dispatcher(void):
last_dispatched_command("{}"_json) {

}

void
dispatcher::set_handler(const string &command, handler_function pHandler){

}

bool
dispatcher::dispatch(json &incoming_json){
  return true;
}

json
dispatcher::get_last_dispatched_command(void) const{
  return last_dispatched_command;
}
}
