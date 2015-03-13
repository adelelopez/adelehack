#include "object.h"

Object::Object () {
   static size_t unique_id = 0;
   id = unique_id++;
   symbol = ' ';
   color = WHITE;
}

void Object::display() {
   display(location);
}

void Object::display(coord loc) {
   attron(COLOR_PAIR(color));
   mvaddch(loc.row, loc.col, symbol);
   attroff(COLOR_PAIR(color));
}

event Object::try_to(Action a, Direction dir) {
   event e;
   e.action = a;
   e.start = location;
   e.end = location.to_the(dir);
   return e;
}

void Object::hold(std::shared_ptr<Object> subject) {
   //subject->owner = shared_from_this();
   subject->location = location;
   inventory.push_back(subject);
}