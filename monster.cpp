#include "monster.h"


std::mt19937 Object::rng;

event Monster::action(int input) {
   std::uniform_int_distribution<int> dist(0, 8);
   auto dir = Direction(dist(rng));
   return try_to(MOVE, dir);
}

Player::Player() {
   symbol = '@';
   color = MAGENTA;
}

event Player::action(int input) {
   switch (input) {
   // movement keys
   case '1':
      return try_to(MOVE, DOWNLEFT);
      break;
   case KEY_DOWN:
   case '2':
      return try_to(MOVE, DOWN);
      break;
   case '3':
      return try_to(MOVE, DOWNRIGHT);
   case KEY_LEFT:
   case '4':
      return try_to(MOVE, LEFT);
      break;
   case KEY_RIGHT:
   case '6':
      return try_to(MOVE, RIGHT);
      break;
   case '7':
      return try_to(MOVE, UPLEFT);
   case KEY_UP:
   case '8':
      return try_to(MOVE, UP);
      break;
   case '9':
      return try_to(MOVE, UPRIGHT);

   case ',':
      return try_to(PICK_UP);
      break;
   }
   return try_to(WAIT);
}

Feline::Feline() {
   symbol = 'f';
   color = YELLOW;
}