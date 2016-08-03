#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -g -c -Wall -Werror
OBJS= word.o p8.o rek.o key.o table.o lex.o chip.o alu.o mem.o progChip.o

p8: $(OBJS)
	g++ -o p8 $(OBJS)

p8.o: p8.cc progChip.o
	g++ $(OPTS) p8.cc

progChip.o: progChip.cc progChip.h chip.o lex.o
	g++ $(OPTS) progChip.cc

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

chip.o: chip.cc chip.h alu.o mem.o
	g++ $(OPTS) chip.cc

alu.o: alu.cc alu.h
	g++ $(OPTS) alu.cc

mem.o: mem.cc mem.h
	g++ $(OPTS) mem.cc

clean:
	rm -f *~ *.o p8