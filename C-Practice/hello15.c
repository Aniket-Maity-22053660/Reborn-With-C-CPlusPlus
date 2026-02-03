#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
  char name[20];
  int age;
} student;

student* fillStruct(student *st1){
  printf("Enter the name of the student:");
  //scanf("%s", st1.name);
  char* name = (char*)malloc(20*sizeof(char));
  gets(name);
  strcpy(st1->name, name);
  //printf("NAME: %s\n", st1.name);
  printf("Enter student's age: ");
  scanf("%d", &st1->age);
  return st1;
  //printf("AGE: %d\n", st1.age);
}

int main(){

  student st1, st2;
  student* (*ptr[])(student*) = {&fillStruct};
  student* st = (*ptr[0])(&st1);
  printf("NAME: %s\n", st->name);
  printf("AGE: %d\n", st->age);
  st2 = st1;
  printf("Size of st2: %ld\n", sizeof(st2));
  return 0;
}
