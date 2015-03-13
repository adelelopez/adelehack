#include "game.h"

Game::Game() {
   level.emplace_back();
   level.front().load_level(at);
   player = std::make_shared<Player>();
   spawn(player, {1, 1});
   spawn(std::make_shared<Feline>(), {1, 3});
   spawn(std::make_shared<Money>(), {3, 4});
}

Outcome Game::transfer(std::shared_ptr<Object> object,
                       std::shared_ptr<Object> old_owner,
                       std::shared_ptr<Object> new_owner) {
   auto& here = old_owner->inventory;
   auto is_here = std::find(here.begin(), here.end(), object);
   if (is_here != here.end()) {
      new_owner->inventory.splice(new_owner->inventory.end(), here, is_here);
      object->location = new_owner->location;
      return SUCCESS;
   }
   return FAIL;
}

Outcome Game::move(std::shared_ptr<Object> subject, coord destination) {
   if (!at[destination]->is_clear())
      return FAIL;

   return transfer(subject, at[subject->location], at[destination]);
}

Outcome Game::pick_up(std::shared_ptr<Object> subject) {
   // TODO: overload transfer with versions that can transfer the entire
   // inventory, and later versions that can sort to transfer specific
   // types of items
   auto& this_place = subject->location;
   for (auto item : at[this_place]->inventory) 
      if (item->is(CARRYABLE))
         // just pick up the top item
         return transfer(item, at[this_place], subject);
   
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
   case PICK_UP:
      pick_up(thing);
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

