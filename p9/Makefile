#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -g -c -Wall -Werror
OBJS= word.o p9.o rek.o key.o table.o lex.o chip.o alu.o mem.o progChip.o fullProg.o

p9: $(OBJS)
	g++ -o p9 $(OBJS)

p9.o: p9.cc fullProg.h
	g++ $(OPTS) p9.cc

fullProg.o: fullProg.cc fullProg.h chip.h
	g++ $(OPTS) fullProg.cc
progChip.o: progChip.cc progChip.h chip.h lex.h
	g++ $(OPTS) progChip.cc

lex.o: lex.cc lex.h table.h
	g++ $(OPTS) lex.cc

table.o: table.cc table.h rek.h
	g++ $(OPTS) table.cc

rek.o: rek.h rek.cc  key.h
	g++ $(OPTS) rek.cc

key.o: key.h key.cc word.h
	g++ $(OPTS) key.cc

word.o: word.h word.cc
	g++ $(OPTS) word.cc

chip.o: chip.cc chip.h alu.h mem.h
	g++ $(OPTS) chip.cc

alu.o: alu.cc alu.h
	g++ $(OPTS) alu.cc

mem.o: mem.cc mem.h
	g++ $(OPTS) mem.cc

clean:
	rm -f *~ *.o p9