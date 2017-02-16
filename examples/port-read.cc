#include <iostream>
#include "port.hpp"

using std::cout;

using akashi::Port;

int main(int argc, char *argv) {
  Port port(9001);
  auto socket = port.accept();

  cout << port.read(socket) << '\n';
  return 0;
}
