#pragma once

#include "coord.h"

class Object;

enum Action {WAIT, MOVE, PICK_UP};

struct event {
   std::shared_ptr<Object> subject;
   int delay;
   Action action;
   coord start;
   coord end;
   std::string success_msg;
   std::string fail_msg;
};

