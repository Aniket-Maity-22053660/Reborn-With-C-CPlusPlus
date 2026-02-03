#include<stdio.h>
#define AREA(length) (length*length)


int main(){

/*
printf("King Star Khan\n");
printf("%d", AREA(25));

char name[] = {'A', 'N', 'I', 'K', 'E', 'T'};
printf("\n%s\n", name);
printf("Enter the numbers: ");
float num1, num2;
scanf("%f %f", &num1, &num2);
printf("%.2f + %.2f = %.2f\n", num1, num2, (num1 + num2));

int i = 0;
char ch;
char word[20];

printf("Enter the characters, press enter to terminate: \n");
getchar();
while(1){
ch = getchar();
word[i++] = ch;
if(word[i-1] == '\n'){
break;
}
}

printf("You entered: %s", word);
char myName[15];
printf("What is your name: ");
gets(myName);
printf("Your name is: ");
puts(myName);
printf("%d", printf("King Star Khan"));
*/
char message[] = "Aniket Maity is a King";
puts(message);
int num = 10;
printf("%p", &num);

const int num1 = 10, num2 = 15;
printf("\n%f", (float)(num1 + num2) / 2);

struct student{
char name[15];
int age;
};

struct student s1 = {"Aniket Maity", 22};
printf("\n%s\n", s1.name);

enum week{mon, tue, wed, thur, fri, sat, sun};
printf("The value of enum week: %d\n", sun + 10);
const int num3 = 90;
int* ptr = &num3;
printf("Value before change of const variable: %d\n", num3);
*ptr = 100;
printf("Value after change of const variable: %d\n", num3);
int arr[] = {1,2,3,4,5,78,6,7};
const int *ptr2 = arr;
printf("Before changing the value in the array: \n");
for(int i = 0 ; i < sizeof(arr) / sizeof(int) ; i++){
printf("%d ", arr[i]);
}
printf("\n");
*(ptr2 + 4) = 90;
for(int i = 0 ; i < sizeof(arr) / sizeof(int) ; i++){
printf("%d ", arr[i]);
}
printf("\n");
return 0;

}
