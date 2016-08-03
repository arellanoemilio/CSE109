#include<stdio.h>
struct rec
{
  int x,y,z;
};

int main()
{
  int counter;
  FILE *ptr_myfile;
  struct rec my_record;

  ptr_myfile=fopen("test.bin","wb");
  if (!ptr_myfile)
    {
      printf("Unable to open file!");
      return 1;
    }
  for ( counter=1; counter <= 10; counter++)
    {
      my_record.x= counter;
      fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
    }
  fclose(ptr_myfile);
  FILE *fin;
  fin = fopen("test.bin", "rb");
  if(!fin){
    printf("unable to read file");
    return 1;
  }
  for(counter = 1; counter < 10; counter++){
    struct rec r;
    fread(&r,sizeof(struct rec),1,fin);
    printf("%d %d %d\n",r.x, r.y, r.z);
  }
  fclose(fin);
  return 0;
}
