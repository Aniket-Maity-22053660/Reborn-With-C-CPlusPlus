#include<iostream>
#include<cstring>

using namespace std;

struct Book{
  char *name;
  int pages;
  char* author;
} book1;

struct Book setBook(struct Book book1){
  book1.name = new char[30];
  book1.author = new char[20];

  book1.name = "Operating System";
  book1.pages = 1200;
  book1.author = "Silberscatz";
  return book1;
}

void printBook(struct Book* book){
  cout<<"Printing Book information:- "<<endl;
  cout<<"Name: "<<book->name<<endl;
  cout<<"Pages: "<<book->pages<<endl;
  cout<<"Author: "<<book->author<<endl;
}

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
  char *name3 = "King";
  char *name4;
  name4 = name3;
  char* names[] = {name4};
  cout<<names[0]<<endl;

  book1 = setBook(book1);
  printBook(&book1);
  struct Book book2;
  book2 = setBook(book2);
  printBook(&book2);
  struct Book* book[] = {&book1, &book2};
  printBook(book[1]);
  struct Book* books = new Book[5];
  *(books + 4) = setBook(*(books+4));
  printBook(books + 4);
  return 0;
}

int calcStrLength(char* name){
  int length = strlen(name);
  return length;
}
