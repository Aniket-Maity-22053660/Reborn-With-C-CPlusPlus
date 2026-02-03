#include<stdio.h>

int main(){

int arr1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int arr2[][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
int arr3[3][3];
for(int i = 0 ; i < 3 ; i++){
for(int  j = 0 ; j < 3 ; j++){
int sum = 0;
for(int k = 0 ; k < 3 ; k++){
sum += arr1[i][k] * arr2[k][j];
}
arr3[i][j] = sum;
}
}

printf("arr1:- \n");
for(int i = 0 ; i < 3 ; i++){
for(int j = 0 ; j < 3 ; j++){
printf("%d ", arr1[i][j]);
}
printf("\n");
}

printf("arr2:- \n");
for(int i = 0 ; i < 3 ; i++){
for(int j = 0 ; j < 3 ; j++){
printf("%d ", arr2[i][j]);
}
printf("\n");
}

printf("arr1 * arr2:- \n");
for(int i = 0 ; i < 3 ; i++){
for(int j = 0 ; j < 3 ; j++){
printf("%d ", arr3[i][j]);
}
printf("\n");
}
return 0;
}
