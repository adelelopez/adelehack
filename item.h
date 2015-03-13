#pragma once

#include "object.h"

class Item : public Object {
public:
   Item() {
       is(WALKABLE) = true;
       is(CARRYABLE) = true;
   };
};

class Money : public Item {
public:
   Money() {
      symbol = '$';
      color = GREEN;
   }
};