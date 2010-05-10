OBJS = main.o word.o vm.o realmachine.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

prog: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o prog

main.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) main.cpp

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

vm.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) vm.cpp

realmachine.o: realmachine.cpp realmachine.h vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) realmachine.cpp

clean:
	\rm *.o


