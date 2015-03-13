#pragma once

#include "event.h"

enum Color {GRAY, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
enum Flag {WALKABLE, CARRYABLE};
enum Outcome {SUCCESS, FAIL};
enum State {WEIGHT};

class Object : public std::enable_shared_from_this<Object> {
   int id;  // objects have a unique id for comparison purposes

protected:
   static std::mt19937 rng;      // random number generator
   std::map<Flag, bool> flag;    // flags for the objects
   std::map<State, int> state;   // states of the objects

public:
   Object();
   // basic characterisitcs 
   char symbol;
   coord location;
   Color color;

   //std::shared_ptr<Object> owner;
   std::list<std::shared_ptr<Object>> inventory;

   bool& is(Flag f) { return flag[f]; }
   bool is_not(Flag f) { return !flag[f]; }

   virtual void display();
   virtual void display(coord);    // sometimes the object appears in a place besides location

   event try_to(Action a = WAIT, Direction dir = NONE);

   virtual event action(int input) { return try_to(); }

   void hold(std::shared_ptr<Object>);

   friend inline bool operator==(const Object& lhs, const Object& rhs);
};

inline bool operator==(const Object& lhs, const Object& rhs) {
   return lhs.id == rhs.id;
}