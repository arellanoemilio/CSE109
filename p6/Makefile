#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -c -Wall -Werror
OBJS= word.o p6.o rek.o key.o table.o

p6: $(OBJS)
	g++ -o p6 $(OBJS)

p6.o: p6.cc word.o rek.o key.o table.o
	g++ $(OPTS) p6.cc

table.o: table.cc table.h rek.o
	g++ $(OPTS) table.cc

rek.o: rek.h rek.cc  key.o
	g++ $(OPTS) rek.cc

key.o: key.h key.cc word.o
	g++ $(OPTS) key.cc

word.o: word.h word.cc
	g++ $(OPTS) word.cc

clean:
	rm -f *~ *.o p6