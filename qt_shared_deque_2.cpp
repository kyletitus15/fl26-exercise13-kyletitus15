// qt_shared_deque_2.cpp
#include <iostream>
#include <cassert>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;

  if (!buffer.create(100)) {
    std::cerr << "Can't create memory";
    return 1;
  }

  while(true){
    int val;
    std::cout << "$>";
    if (!(std::cin >> val)) { break; }


    if(buffer.enqueue(val)){ 
      std::cout << "Enqueued: " << val << "\n";
    }
    else {
      std::cout << "Buffer full" << "\n";
      break;
    }
  }

  return 0;
}
