#include <iostream>
#include "port.hpp"

using std::cout;

using akashi::Port;

int main(int argc, char** argv) {
  Port port(9001);
  port.accept();

  for(;;) {
    string s = port.read();
    if(s == "end") {
      break;
    }
    port.send(s);
  }
  return 0;
}
