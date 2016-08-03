#include <stdio.h>

/*
  Read a sequence of no more than 200 non-zero ints that is terminate
  by 0. Display them. Sort them. Display them again.
*/

void intro(){
  printf("A program that reads in non-zeor ints, stopping  at 0 \n dispaly them, sort them, and display them again \n\0");
}
void getData(int d[],int  *index){
  printf("Enter the ints- ");
  int temp = 0;
  *index = 0;
  scanf("%i",&temp);
  while (temp != 0 && *index < 200){
    d[(*index)] = temp;
    (*index)++;
    scanf("%d",&temp);
  }
}

void print(char* s, int d[],int index){
  int i;
  printf("the %s list \n",s);
  for( i = 0;i < index; i++){
    printf("%d \n",d[i]);
  }
}

void sort(int d[], int index){
  int i = 0;
  int good = 0;
  while(good < 1){
    good = 1;
    while(i < index-1){
      if (d[i]>d[i+1]){
	int temp =d[i];
	d[i] = d[i+1];
	d[i+1] = temp;
	good = 0;
      }
      i++;
    }
    i = 0;
  }
}

int main(int ct,char **arg){
   int x[200],count;
   intro();
   getData(x,&count);
   print("unsorted",x,count);
   sort(x,count);
   print("sorted",x,count);
   return 0;
 }

/*SAMPLE OUTPUT
A program that reads in non-zero ints, stopping at 0
Display them, sort them, and display then again
Enter the ints-  7 2 3 8 5 -9 2 0
The unsorted list
 2
 8
 5
 3
 2
 7
 -9
----------------
The sorted list
 -9
 2
 2
 3
 5
 7
 8
----------------
*/
