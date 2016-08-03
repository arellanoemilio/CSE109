#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -g -c -Wall -Werror
OBJS= word.o p7.o rek.o key.o table.o lex.o

p7: $(OBJS)
	g++ -o p7 $(OBJS)

p7.o: p7.cc word.o rek.o key.o table.o
	g++ $(OPTS) p7.cc

lex.o: lex.cc lex.h table.o
	g++ $(OPTS) lex.cc

table.o: table.cc table.h rek.o
	g++ $(OPTS) table.cc

rek.o: rek.h rek.cc  key.o
	g++ $(OPTS) rek.cc

key.o: key.h key.cc word.o
	g++ $(OPTS) key.cc

word.o: word.h word.cc
	g++ $(OPTS) word.cc

clean:
	rm -f *~ *.o p7