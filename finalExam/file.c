#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE* fin, *fout;
  fin = fopen("testread.c", "r");
  if(fin == NULL){
    fprintf(stderr,"File can not be opened");
    exit(1);
  }

  fout = fopen("testwrite.c","w");
  if(fout == NULL){
    fprintf(stderr,"File can not be opened");
    exit(1);
  }

  char ch;
  int number;
  fscanf(fin,"%d",&number);
  while(!feof(fin)){
    fprintf(fout,"%d ",number);
    fscanf(fin,"%d",&number);
  }
  fclose(fin);
  fclose(fout);
}
