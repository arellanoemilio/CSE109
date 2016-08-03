#Makefile for p4                                                                                     
#Emilio Arellano
#CSE 109                                             
#Spring 2015

OPTS= -c -Wall -Werror
OBJS= word.o p5.o

p5: $(OBJS)
	g++ -o p5 p5.o word.o

p5.o: p5.cc word.o
	g++ $(OPTS) p5.cc

word.o: word.h word.cc
	g++ $(OPTS) word.cc
clean:
	rm -f *~ *.o p5