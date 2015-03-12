#pragma once

#include "monster.h"
#include "place.h"
#include "level.h"

class Game {
   // environment
   int input;

   // levels are mostly used to save information
   std::list<Level> level;
   int cur_lvl;

   void close_level();

   // nouns
   std::shared_ptr<Monster> player;
   std::list<std::shared_ptr<Object>> items;
   std::map<coord, std::shared_ptr<Place>> at;

   // verbs
   Outcome move(std::shared_ptr<Object>, coord);
   Outcome spawn(std::shared_ptr<Object>, coord);

   // events
   void take_turn();
   void process_event(std::shared_ptr<Object> thing, event &e);

public:
   Game();

   void loop();
   void display();
};