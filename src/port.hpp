/**   Port
**
**    This file contains a Port class to listen sepecified port and communicate
**    with other process via this port.
**/
#ifndef PORT_HPP
#define PORT_HPP

#include <cstdint>
#include <memory>
#include <string>

#include <asio.hpp>

using std::string;
using std::unique_ptr;
using asio::io_service;
using asio::ip::tcp;

namespace akashi {

class Port {
public:
  /** Port Constructor
  **  Initializes and instanatiates a Port.
  **
  **  Parameters:
  **  port    uint32_t        Port Number
  **/
  Port(const uint32_t port);

  /** Accept
  **  Waits for incoming request and Accepts it.
  **
  **  Returns:
  **  unique_ptr<socket>      Unique pointer to established socket
  **
  **  Reference:
  **  Unique pointer is a kind of Smart pointer introduced into C++ in C++11.
  **  For more information on smart pointer, see books with C++11 content
  **  such as "C++ Primer 5ed.".
  **/
  void accept(void);

  /** Read
  **  Reads data from accepted connection.
  **
  **  Parameters:
  **  socket_ptr  unique_ptr<socket_ptr>&     Unique pointer to established
                                              socket
  **
  **  Returns:
  **  string      Data from accepted connection
  **/
  string read() const;

  /** Send
  **  Sends data via accepted connection.
  **
  **  Parameters:
  **  data    const string&   Data to transmit
  **/
  void send(const string &) const;

private:
  const uint32_t _port;
  unique_ptr<tcp::socket> _socket_ptr;

};
/* Ending of namespace akashi */
}

#endif
