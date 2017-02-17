/**   Implementation of Port
**
**    See examples/port for une cases.
**/
#include <memory>
#include <iostream>

#include "asio.hpp"

#include "port.hpp"

using std::exception;
using std::unique_ptr;
using std::cout;
using std::cerr;

using asio::ip::tcp;
using asio::error_code;
using asio::buffer;

const int max_char_length = 1024;

namespace akashi {

Port::Port(const uint32_t port):_port(port) {

}

void
Port::accept() {
  io_service io_service;
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), this->_port));
  this->_socket_ptr = unique_ptr<tcp::socket>(new tcp::socket(io_service));
  cout << "Waiting for incomming connection.\n";
  acceptor.accept(*this -> _socket_ptr);
  cout << "Connection Established.\n";
}

string
Port::read() const {
  string read_string("");
  try {
    // Clear the buffer
    char char_buffer[max_char_length] = {'\0'};
    error_code error;
    this -> _socket_ptr -> read_some(buffer(char_buffer), error);
    if(error) {
      asio::system_error(error);
    }
    cout << "Incomming message:" << string(char_buffer) <<'\n';
    read_string += string(char_buffer);
  }
  catch (exception& e) {
    cerr << e.what() << '\n';
    return "error";
  }
  cout << "Read from Socket: " << read_string << '\n';
  return read_string;
}

void
Port::send(const string& data) const {
  char* c_data = const_cast<char*>(data.c_str());
  size_t length = data.length();
  try {
    this -> _socket_ptr -> write_some(asio::buffer(c_data, length));
  }
  catch (exception& e) {
    cerr << e.what() << '\n';
  }
}
}
