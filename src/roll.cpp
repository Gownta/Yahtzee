#include "roll.h"
#include <iostream>

std::ostream & operator<<(std::ostream & os, const Roll & roll) {
  os << "(" << roll.ith(0) << ", "
            << roll.ith(1) << ", "
            << roll.ith(2) << ", "
            << roll.ith(3) << ", "
            << roll.ith(4) << ")";
  return os;
}

