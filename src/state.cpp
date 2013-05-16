#include "state.h"
#include <iostream>

std::ostream & operator<<(std::ostream & os, const Category category) {
  switch (category) {
    case ONES:        os << "1s"; break;
    case TWOS:        os << "2s"; break;
    case THREES:      os << "3s"; break;
    case FOURS:       os << "4s"; break;
    case FIVES:       os << "5s"; break;
    case SIXES:       os << "6s"; break;

    case TRIPLE:      os << "triple"; break;
    case QUAD:        os << "quad"; break;
    case FULL:        os << "full"; break;
    case SMALL:       os << "small"; break;
    case LARGE:       os << "large"; break;
    case CHANCE:      os << "chance"; break;
    case YAHTZEE:     os << "yahtzee"; break;
  }
  return os;
}

std::ostream & operator<<(std::ostream & os, const Roll roll) {
  for (int r = 1; r <= 6; ++r) for (int i = 0; i < roll.count(r); ++i) os << r << " ";
  return os;
}

std::ostream & operator<<(std::ostream & os, const State state) {
  os << "=== Yahtzee State ===\n"
     << "1s      = " << (state.can_use(ONES)    ? " " : "-") << "\n"
     << "2s      = " << (state.can_use(TWOS)    ? " " : "-") << "\n"
     << "3s      = " << (state.can_use(THREES)  ? " " : "-") << "\n"
     << "4s      = " << (state.can_use(FOURS)   ? " " : "-") << "\n"
     << "5s      = " << (state.can_use(FIVES)   ? " " : "-") << "\n"
     << "6s      = " << (state.can_use(SIXES)   ? " " : "-") << "\n"
     << "(total  = " << state.get_topscore() << ")\n\n"
     << "triple  = " << (state.can_use(TRIPLE)  ? " " : "-") << "\n"
     << "quad    = " << (state.can_use(QUAD)    ? " " : "-") << "\n"
     << "full    = " << (state.can_use(FULL)    ? " " : "-") << "\n"
     << "small   = " << (state.can_use(SMALL)   ? " " : "-") << "\n"
     << "large   = " << (state.can_use(LARGE)   ? " " : "-") << "\n"
     << "chance  = " << (state.can_use(CHANCE)  ? " " : "-") << "\n"
     << "yahtzee = " << (state.can_bonus() ? "*" : state.can_use(YAHTZEE) ? " " : "-") << "\n"
  ;
  return os;
}

