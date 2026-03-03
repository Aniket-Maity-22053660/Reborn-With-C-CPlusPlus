#include<iostream>
#include<cstring>

using namespace std;

int calcStrLength(char* name);
int main(){

  int num[] = {10, 20, 30, 40, 50};
  cout<<num<<endl;
  for(int i = 0 ; i < 5 ; i++){
    cout<<num + i<<endl;
  }
  putchar('\n');
  for(int i = 0 ; i < 5 ; i++){
    cout<<*(num + i)<<endl;
  }
  int *num1 = num;
  for(int i = 0 ; i < 5 ; i++){
    cout<<*(num1+i)<<" stored at memory location: "<<(num1 + i)<<endl;
  }
  int **num2 = &num1;
  for(int i = 0 ; i < 5 ; i++){
    cout<<*(*(num2) + i)<<" ";
  }
  putchar('\n');
  int ***num3 = &num2;
  for(int i = 0 ; i < 5 ; i++){
    cout<<*(*(*(num3)) + i)<<" ";
  }
  putchar('\n');
  int ***num4[] = {num3};
  for(int i = 0 ; i < 5 ; i++){
    cout<<*(*(*(*(num4 + 0))) + i)<<" ";
  }
  putchar('\n');
  int arr[4][4] = {{1, 2, 3, 4},
		   {5, 6, 7, 8},
		   {9, 10, 11, 12},
		   {13, 14, 15, 16}
                  };
  cout<<"(arr + 0): "<<(arr + 0)<<endl;
  cout<<"*(arr + 0): "<<*(arr + 0)<<endl;
  int (*ptr)[4] = arr;
  cout<<(ptr + 0)<<endl;
  for(int i = 0 ; i < 4 ; i++){
    for(int j = 0 ; j < 4 ; j++){
      printf("%3d", *(*(ptr + i) + j));
    }
    cout<<'\n';
  }
  int arr2[] = {10, 20, 30, 40, 50};
  int (*ptr1)[5] = &arr2;
  for(int i = 0 ; i < 4 ; i++){
    cout<<*(*(ptr1 + 0) + i)<<" ";
  }
  cout<<'\n';
  cout<<arr2<<endl<<&arr2<<endl;
  char name[30] = "Aniket Maity!";
  cout<<name<<": "<<calcStrLength(name)<<endl;
  char* name1 = new char[100];
  cout<<"Enter your name: ";
  cin.getline(name1, 100);
  cout<<"Your  name is "<<name1<<endl;
  //name = "King star khan!";
  strcpy(name, "King star khan!");
  cout<<name<<": "<<calcStrLength(name)<<endl;
  return 0;
}

int calcStrLength(char* name){
  int length = strlen(name);
  return length;
}
