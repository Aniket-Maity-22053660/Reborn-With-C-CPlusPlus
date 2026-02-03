#include<stdio.h>

int main(){
long long int num = 999999999999999999;
printf("The value of long: %lld\n", num);
int num2 = 0234;
int num3 = 0xa1;
printf("Value of Octal: %o\n", num2);
printf("Value of Hexadecimal: %x\n", num3);
printf("Octal to decimal: %d\n", num2);
printf("Hexadecimal to decimal: %d\n", num3);
float x = 3.4, y = -3.9;
printf("Value of x: %f\n", x);
printf("Value of y: %f\n", y);
char arr[100];
printf("Enter your name: ");
gets(arr);
printf("Your name is: ");
puts(arr);
for(int i = 0 ; ; i++){
//printf("\a");
break;
}

return 0;
}
