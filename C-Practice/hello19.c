#include<stdio.h>

int main(){
  FILE* fp;
  fp = fopen("new.txt", "w");

  for(int i = 0 ; i < 256 ; i++){
    char ch = (char)i;
    fputc(ch, fp);
    if(i % 20 == 0){
      fputc('\n', fp);
    }
  }

  
  return 0;
}
