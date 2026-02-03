#include<stdio.h>

int main(int argc, char* argv[]){
printf("argc = %d\n", argc);
//printf("%s\n", argv[0]);
//printf("%s\n", argv[1]);
for(int i = 0 ; i <= 3 ; i++){
printf("%s\n", argv[i]);
}
return 0;
}
