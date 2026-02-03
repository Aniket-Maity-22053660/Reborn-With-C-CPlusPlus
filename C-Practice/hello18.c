#include<stdio.h>

int main(){
  FILE* fp;
  char ch;
  fp = fopen("hello15.c", "r");
  while(1){
    ch = fgetc(fp);
    if(ch == EOF){
      break;
    }
    printf("%c", ch);
  }
  fp = fopen("star.txt", "w");
  char* arr[] = {"Aniket Maity\n", "King Star Khan\n", "Aniket Maity is a King!\n"};
  for(int i = 0 ; i < 3 ; i++){
    fputs(arr[i], fp);
  }
  return 0;
}
