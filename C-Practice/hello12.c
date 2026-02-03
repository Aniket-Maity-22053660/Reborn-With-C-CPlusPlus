#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  //char name[10] = "Aniket";
  //name = "King Star";
  //char *myName = (char*)malloc(sizeof(char));
  //strcpy(myName, "King Star Khan");
  //printf("%s\n", myName);
  //name = "King Star";
  //strcpy(name, "King Star");
  //printf("%s\n", name);
  /*char* name[10];
  name[0] = (char*)malloc(10*sizeof(int));
  strcpy(name[0], "Aniket King Star");
  char names[10][10];
  //names[0] = "Aniket Star Maity";
  strcpy(names[0], "Aniket Star Maity");
  printf("%s\n", name[0]);
  printf("%s\n", names[0]);
  printf("String Length: %d\n", strlen(names[0]));
  printf("Address of names: %x\n", names);
  //strcpy()
  */
  static float* arr[10];
  for(int i = 0 ; i < 10 ; i++){
    printf("arr[%d] = %X\n", (i+1), arr[i]);
  }
  for(int i = 0 ; i < 10 ; i++){
    arr[i] = (float*)calloc(1, sizeof(float));
    *arr[i] = (float)(i + 100);
  }
  for(int i = 0 ; i < 10 ; i++){
    printf("arr[%d] = %X\n", (i+1), arr[i]);
  }
  printf("\n");
  for(int i = 0 ; i < 10 ; i++){
    printf("*arr[%d] = %0.2f\n", (i+1), *arr[i]);
  }
  return 0;
  
}





























