#ifndef GOWNTA_STATE_H
#define GOWNTA_STATE_H

#include <iosfwd>
#include "roll.h"

enum Category {
  ONES       = 0x40,
  TWOS       = 0x80,
  THREES     = 0x100,
  FOURS      = 0x200,
  FIVES      = 0x400,
  SIXES      = 0x800,

  TRIPLE     = 0x1000,
  QUAD       = 0x2000,
  FULL       = 0x4000,
  SMALL      = 0x8000,
  LARGE      = 0x10000,
  CHANCE     = 0x20000,

  YAHTZEE    = 0x40000,
  SCRATCHEDY = 0x80000,
};
std::ostream & operator<<(std::ostream & os, Category category);
static const int NUM_CATEGORIES = 14;

class State {
  int state;

public:
  State() : state(0) {}
  State(int i) : state(i) {}
  int to_int() const { return state; }

  bool used(Category category) const { return state & category; }
  void set(Category category) { state |= category; }
  bool all_used() const { return (state & 0x4ffc0) == 0x4ffc0; }

  int topscore() const { return state % 64; }
  void addtop(int k) {
    int newtop = topscore() + k;
    if (newtop > 63) newtop = 63;
    state &= ~0x3f;
    state |= newtop;
  }
};

std::ostream & operator<<(std::ostream & os, const State & state);

#endif // GOWNTA_STATE_H

