#ifndef GOWNTA_STATE_H
#define GOWNTA_STATE_H

#include <iosfwd>
#include <cassert>

///////////////////////////////////////
// Score Categories

enum Category {
  ONES       = 0x1,
  TWOS       = 0x2,
  THREES     = 0x4,
  FOURS      = 0x8,
  FIVES      = 0x10,
  SIXES      = 0x20,

  TRIPLE     = 0x40,
  QUAD       = 0x80,
  FULL       = 0x100,
  SMALL      = 0x200,
  LARGE      = 0x400,
  CHANCE     = 0x800,
  YAHTZEE    = 0x1000,
};

std::ostream & operator<<(std::ostream & os, Category category);

///////////////////////////////////////
// Roll class

class Roll {
  int n_1 : 3;
  int n_2 : 3;
  int n_3 : 3;
  int n_4 : 3;
  int n_5 : 3;
  int n_6 : 3;

public:
  Roll(int n1, int n2, int n3, int n4, int n5, int n6)
      : n_1(n1), n_2(n2), n_3(n3), n_4(n4), n_5(n5), n_6(n6) {}

  Roll(int e) {
    // TODO
  }
  int to_int() const {
    // TODO
    return 0;
  }

  int count(int v) const {
    switch (v) {
      case 1: return n_1;
      case 2: return n_2;
      case 3: return n_3;
      case 4: return n_4;
      case 5: return n_5;
      case 6: return n_6;
    }
    assert(false);
    return 0;
  }
};

std::ostream & operator<<(std::ostream & os, Roll roll);

///////////////////////////////////////
// State class

class State {
  int state;
  // bits 1-13 are for used-ness of categories
  // bit  14 represents the availablility of bonus yahtzees
  // bits 15-20 are the top-section total (0..63)
  // bits 21-28 represent the current roll (10 choose 5 = 252 combinations)
  // bits 29-30 represent the number of rolls

public:
  State(int i = 0) : state(i) {}
  int to_int() const { return state; }

  bool  can_use(Category category) const { return !(state & category); }
  State set_use(Category category) const { assert(can_use(category)); return State(state | category); }

  bool  can_bonus() const { return state & 0x2000; }
  State set_bonus() const { return State(state | 0x2000); }

  int   get_topscore()      const { return (state >> 14) % 64; }
  State inc_topscore(int k) const {
    int ts = get_topscore();
    if (k + ts > 63) k = 63 - ts;
    return State(state + k*0x4000);
  }

  Roll  get_roll()          const { return Roll((state >> 21) % 256); }
  State set_roll(Roll roll) const { return State((state & ~(255 << 21)) | (roll.to_int() << 21)); }

  int   get_num_rolls() const { return (state >> 28) % 4; }
  State inc_num_rolls() const { return State(state + 0x10000000); }
};

std::ostream & operator<<(std::ostream & os, State state);

#endif // GOWNTA_STATE_H

