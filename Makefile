OBJS = main.o gui.o word.o vm.o realmachine.o gui_notebook_item.o gui_memory_window.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
PKGCONFIG = `pkg-config --cflags --libs gtk+-2.0 gtksourceview-2.0`

prog: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o prog $(PKGCONFIG)

main.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) main.cpp $(PKGCONFIG)

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

vm.o: vm.cpp vm.h word.cpp word.h
	$(CC) $(CFLAGS) vm.cpp

pagingtable.o: pagingtable.h pagingtable.cpp
	$(CC) $(CFLAGS) pagingtable.cpp

realmachine.o: realmachine.cpp realmachine.h vm.o word.o pagingtable.o
	$(CC) $(CFLAGS) realmachine.cpp

gui_notebook_item.o: gui_notebook_item.h gui_notebook_item.cpp
	$(CC) $(CFLAGS) gui_notebook_item.cpp $(PKGCONFIG)

gui_memory_window.o: gui_memory_window.h gui_memory_window.cpp
	$(CC) $(CFLAGS) gui_memory_window.cpp $(PKGCONFIG)
	
gui.o: gui.cpp gui.h realmachine.o vm.o word.o gui_notebook_item.o gui_memory_window.o
	$(CC) $(CFLAGS) gui.cpp $(PKGCONFIG)

clean:
	\rm *.o


