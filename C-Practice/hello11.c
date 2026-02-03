#include<stdio.h>
#include<stdlib.h>
#define length 5



int main(){
  printf("King Star Khan\n");
  int arr[length];
  /*for(int i = 0 ; i < length ; i++){
    printf("Enter the %dth  element: ", i+1);
    scanf("%d", &arr[i]);
  }
  printf("Display of Array:-\n");

  for(int i = 0 ; i < length ; i++){
    printf("%d ", arr[i]);
  }
  */
  int* ptr = (int*)malloc(10*sizeof(int));
  //ptr = NULL;
  if(ptr == NULL){
    goto END;
  }
  /*printf("Enter the elements for dynamic array:-\n");
  for(int i = 0 ; i < 4 ; i++){
    printf("Enter the %dth element: ", i+1);
    scanf("%d", ptr+i);
  }
  */
  printf("Displaying dynamic array:-\n");
  for(int i = 0 ; i < 4 ; i++){
    printf("%d ", *(ptr + i));
  }

 END:
  printf("\nMemory could not allocated successfully!\n");
  printf("\n");
  return 0;
}
