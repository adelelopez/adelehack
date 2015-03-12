#pragma once

#include "object.h"

class Monster : public Object {
public:
   Monster() {};

   event action(int input);
};

class Player : public Monster {
public:
   Player();

   event action(int input);
};

class Feline : public Monster {
public:
   Feline();
};

