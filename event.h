#pragma once

#include "coord.h"

class Object;

enum Action {WAIT, MOVE, PICK_UP};
enum Outcome {SUCCESS, FAIL};

struct event {
   std::shared_ptr<Object> subject;
   int delay;
   Action action;
   coord start;
   coord end;
};

