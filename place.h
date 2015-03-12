#pragma once

#include "object.h"

// places are responsible for their inventory
// i.e. all the stuff on their tile
class Place : public Object {
public:
   Place(int row, int col) {
      location = {row, col};
   }

   bool is_clear() {
      bool clear = true;
      for (auto& a : inventory)
         clear &= a->is(WALKABLE);
      return clear & is(WALKABLE);
   }

   void display() {
      Object::display();
      for (auto& contents : inventory) {
         contents->display();
      }
   }
};

class Floor : public Place {
public:
   Floor(int row, int col) : Place(row, col) {
      symbol = '.';
      is(WALKABLE) = true;
   }
};

class Wall : public Place {
public:
   Wall(int row, int col) : Place(row, col) {
      symbol = '#';
      is(WALKABLE) = false;
      color = WHITE;
   }
};