OBJS = main.o gui.o word.o vm.o realmachine.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
PKGCONFIG = `pkg-config --cflags --libs gtk+-2.0`

prog: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o prog $(PKGCONFIG)

main.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) main.cpp $(PKGCONFIG)

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

vm.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) vm.cpp

realmachine.o: realmachine.cpp realmachine.h vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) realmachine.cpp
	
gui.o: gui.cpp gui.h realmachine.cpp realmachine.h vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) gui.cpp $(PKGCONFIG)

clean:
	\rm *.o


