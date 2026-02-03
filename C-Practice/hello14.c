#include<stdio.h>
#include<string.h>
#define max(num1, num2) ((num1 > num2) ? num1 : num2)

void swapNames(char** name1, char** name2){
  char* temp = *name1;
  *name1 = *name2;
  *name2 = temp;
}
int main(){

  char* name1 = "Aniket";
  char* name2 = "King Star";
  printf("Before swapping:-\nname1: %s name2: %s\n", name1, name2);
  swapNames(&name1, &name2);
  printf("After swapping:-\nname1: %s name2: %s\n", name1, name2);
  printf("name1: %s\n", name1);
  printf("*name1: %c\n", *name2);
  return 0;
}
