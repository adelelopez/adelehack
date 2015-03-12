#pragma once

#include <map>
#include <list>
#include <queue>
#include <memory>
#include <random>
#include <ncurses.h>
#include <algorithm>

enum Direction {NONE, RIGHT, UPRIGHT, UP, UPLEFT, LEFT, DOWNLEFT, DOWN, DOWNRIGHT};

struct coord {
   int row;
   int col;

   // convenient way to get the coordinates from a relative direction
   coord to_the(Direction dir) {
      int r = row;
      int c = col;
      switch (dir) {

      case RIGHT:
         c++;
         break;
      case UPRIGHT:
         c++; r--;
         break;
      case UP:
         r--;
         break;
      case UPLEFT:
         c--; r--;
         break;
      case LEFT:
         c--;
         break;
      case DOWNLEFT:
         r++; c--;
         break;
      case DOWN:
         r++;
         break;
      case DOWNRIGHT:
         c++; r++;
         break;
      default: break;
      }
      return {r, c};
   }

};

// lexicographical ordering 
inline bool operator< (const coord& lhs, const coord& rhs) {
   if (lhs.row == rhs.row)
      return lhs.col < rhs.col;
   else
      return lhs.row < rhs.row;
}