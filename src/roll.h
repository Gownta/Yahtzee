#ifndef GOWNTA_ROLL_H
#define GOWNTA_ROLL_H

#include <cassert>
#include <iosfwd>

class Roll {
  int c1 : 4;
  int c2 : 4;
  int c3 : 4;
  int c4 : 4;
  int c5 : 4;
  int c6 : 4;

  void set(int r, int v) {
    assert(0 <= v);
    assert(v <= 5);
    assert(1 <= r);
    assert(r <= 6);

    switch (r) {
      case 1: c1 = v; break;
      case 2: c2 = v; break;
      case 3: c3 = v; break;
      case 4: c4 = v; break;
      case 5: c5 = v; break;
      case 6: c6 = v; break;
    }
  }

public:
  Roll(int c1, int c2, int c3, int c4, int c5, int c6) : c1(c1), c2(c2), c3(c3), c4(c4), c5(c5), c6(c6) {}
  Roll() : Roll(5,0,0,0,0,0) {}

  int count(int r) const {
    switch (r) {
      case 1: return c1;
      case 2: return c2;
      case 3: return c3;
      case 4: return c4;
      case 5: return c5;
      case 6: return c6;
    }
    assert(false);
  }

  void inc(int r) { set(r, count(r) + 1); }
  void dec(int r) { set(r, count(r) - 1); }

  // what is the i'th die's value
  int ith(int i) const {
    assert(0 <= i);
    assert(i <  5);
    for (int r = 1; r <= 6; ++r) {
      int nr = count(r);
      if (i < nr) return r;
      i -= nr;
    }
    assert(false);
  }
};

std::ostream & operator<<(std::ostream & os, const Roll & roll);

#endif // GOWNTA_ROLL_H

