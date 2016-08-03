#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -c -Wall -Werror
OBJS= p4.o alu.o chip.o mem.o

p4: $(OBJS)
	g++ -o p4 p4.o alu.o chip.o mem.o

p4.o: p4.cc chip.h mem.h
	g++ $(OPTS) p4.cc

chip.o: chip.h chip.cc mem.h
	g++ $(OPTS) chip.cc

mem.o: mem.cc mem.h
	g++ $(OPTS) mem.cc

alu.o: alu.h alu.cc
	g++ $(OPTS) alu.cc
clean:
	rm -f *~ *.o p4