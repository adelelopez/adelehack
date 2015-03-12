#pragma once

#include "place.h"

class Level {
   std::map<coord, std::shared_ptr<Place>> at;
public:

   Level () {
      create_room_level(7, 14);
   }

   void load_level(std::map<coord, std::shared_ptr<Place>> &at) {
      std::swap(this->at, at);
   }

   void create_room_level(int rows, int cols) {
      for (int r = 0; r != rows; ++r)
         for (int c = 0; c != cols; ++c) {
            if (r == 0 || c == 0 || r == rows - 1 || c == cols - 1)
               at[ {r, c}] = std::make_shared<Wall>(r, c);
            else
               at[ {r, c}] = std::make_shared<Floor>(r, c);
         }
   }
};