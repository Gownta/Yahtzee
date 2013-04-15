#include "state.h"
#include <iostream>

std::ostream & operator<<(std::ostream & os, Category category) {
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
    case SCRATCHEDY:  os << "--"; break;
  }
  return os;
}

std::ostream & operator<<(std::ostream & os, const State & state) {
  os << "=== Yahtzee State ===\n"
     << "1s      = " << (state.used(ONES) ? "-" : " ") << "\n"
     << "2s      = " << (state.used(TWOS) ? "-" : " ") << "\n"
     << "3s      = " << (state.used(THREES) ? "-" : " ") << "\n"
     << "4s      = " << (state.used(FOURS) ? "-" : " ") << "\n"
     << "5s      = " << (state.used(FIVES) ? "-" : " ") << "\n"
     << "6s      = " << (state.used(SIXES) ? "-" : " ") << "\n"
     << "(total  = " << state.topscore() << ")\n\n"
     << "triple  = " << (state.used(TRIPLE) ? "-" : " ") << "\n"
     << "quad    = " << (state.used(QUAD) ? "-" : " ") << "\n"
     << "full    = " << (state.used(FULL) ? "-" : " ") << "\n"
     << "small   = " << (state.used(SMALL) ? "-" : " ") << "\n"
     << "large   = " << (state.used(LARGE) ? "-" : " ") << "\n"
     << "chance  = " << (state.used(CHANCE) ? "-" : " ") << "\n"
     << "yahtzee = " << (state.used(YAHTZEE) ? state.used(SCRATCHEDY) ? "-" : "*" : " ") << "\n"
  ;
  return os;
}

