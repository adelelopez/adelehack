OBJS = game.o monster.o object.o
CC = g++ -std=c++1y
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

adelehack : $(OBJS) main.cpp
	$(CC) $(LFLAGS) $(OBJS) main.cpp -lncurses -o adelehack 

game.o : game.h game.cpp level.h place.h monster.h object.h coord.h event.h item.h
	$(CC) $(CFLAGS) game.cpp

object.o : object.h object.cpp coord.h event.h
	$(CC) $(CFLAGS) object.cpp

monster.o : monster.h monster.cpp object.h coord.h event.h
	$(CC) $(CFLAGS) monster.cpp

clean:
	\rm *.o *~ adelehack
