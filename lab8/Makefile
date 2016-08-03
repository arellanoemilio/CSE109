#Makefile for CSE 109 Lab8
#Edwin Kay
#Spring 2015

#user provides lab8.cc
#the command "make header" brings in the needed .h files
#the command "make" starts by bringing in the corresponding .o files
#before compiling lab8.cc

CP= g++ -c -g -Wall -Werror

lab8: lab8.o 
	cp /proj/cse109/lab8/*.o .
	g++ -o lab8 lab8.o table.o word.o key.o rek.o lex.o 

lab8.o: lab8.cc table.h  word.h rek.h lex.h key.h 
	$(CP) lab8.cc

headers:
	cp /proj/csc109/lab8/*.h .
clean:
	rm -f *.o *~ lab8
