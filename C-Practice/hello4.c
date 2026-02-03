#include<stdio.h>

int main(){
char a = 71;
int choi;
printf("Enter your choice: ");
choi = getchar();
getchar();
if (choi == 65){
goto start;
}
unsigned char b = a;
printf("a = %d\n", a);
printf("b = %d\n", b);
printf("'C' - '1' = %c\n", ('C' - 1));
printf("!15 = %d\n", !15);

start: 
char ch;
printf("Enter the character: ");
scanf("%c", &ch);
switch(ch){
case 'E' ... 'H':
printf("You entered A\n");
//break;
case 'B':
printf("You entered B\n");
//break;
case 'C':
printf("You entered C\n");
//break;
case 'D':
printf("You entered D\n");
//break;
default:
printf("Wrong Choice!\n");
}
return 0;
}
