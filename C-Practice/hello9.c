x#include<stdio.h>
#include<math.h>

double* fun1(int num){
static double arr[3];
arr[0] = pow(num, 2);
arr[1] = pow(num, 3);
arr[2] = pow(num, 4);
return arr;
}
int num= 100;
double* arr = fun1(num);
for(int i = 0 ; i < 3 ; i++){
  printf("%0.2f\n",arr[i]);
}
return 0;
}
