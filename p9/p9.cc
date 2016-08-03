/*Emilio Arellano
  CSE 109
  p8.cc           */

#include "fullProg.h"

int main(int argc, char *argv[]){
  bool verbose;
  ifstream in;
  if(argc == 2){
    verbose  = false;
    in.open(argv[1]);
  }else if(argc == 3){
    in.open(argv[1]);
    ProgChip::check(strcmp(argv[2],"-v") == 0,"Error: main(): comand line is not valid, check ",argv[2]);
    verbose = true;
    }
  else{
    ProgChip::check(false,"Error: main(): invalid number of inputs in comand line");
  }
  ProgChip::check(in.good(),"Error: main():Cannot open file ",argv[1]);
  FullProg chip;
  chip.load(in);
  chip.run(verbose);
  return 0;
}
