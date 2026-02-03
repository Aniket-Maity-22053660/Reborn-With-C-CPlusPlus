#include<stdio.h>
#include "hello7.c"

void fun1(){
printf("Value of num inside fun1: %d\n", num);
num++;
}

void fun2(){
printf("Value of num inside fun2: %d\n", num);
num++;
}

int main(){

static int x;
printf("Value of x: %d\n", x);
printf("Value of num before calling the functions: %d\n", num);
for(int i = 0 ; i < 20 ; i++) fun1();
printf("Value of num after calling the fun1: %d\n", num);
for(int i = 0 ; i < 30 ; i++) fun2();
printf("Value of num after calling hte fun2: %d\n", num);
return 0;
}
