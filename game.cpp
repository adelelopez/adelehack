#include "game.h"

Game::Game() {
   level.emplace_back();
   level.front().load_level(at);
   player = std::make_shared<Player>();
   spawn(player, {1, 1});
   spawn(std::make_shared<Feline>(), {1, 3});
   spawn(std::make_shared<Feline>(), {1, 4});
}

Outcome Game::move(std::shared_ptr<Object> subject, coord destination) {
   if (!at[destination]->is_clear())
      return FAIL;

   auto& here = at[subject->location]->inventory;
   auto is_here = std::find(here.begin(), here.end(), subject);
   if (is_here != here.end()) {
      at[destination]->inventory.splice(at[destination]->inventory.end(), here, is_here);
      subject->location = destination;
      subject->owner = at[destination];
      return SUCCESS;
   }
   return FAIL;
}

Outcome Game::spawn(std::shared_ptr<Object> subject, coord location) {
   subject->location = location;
   items.push_back(subject);
   at[location]->hold(subject);
   return SUCCESS;
}

void Game::take_turn() {
   for (auto& thing : items) {
      auto e = thing->action(input);
      process_event(thing, e);
   }
}

void Game::process_event(std::shared_ptr<Object> thing, event &e) {
   switch (e.action) {
   case MOVE:
      move(thing, e.end);
      break;
   case WAIT:
   default:  break;
   }
}

void Game::display() {
   for (auto& place : at)
      place.second->display();
}

void Game::loop() {
   display();
   while ((input = getch()) != KEY_F(1)) {
      take_turn();
      display();
   }
}

