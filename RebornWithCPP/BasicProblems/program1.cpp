#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main(){
  extern string name;
  cout<<name<<endl;
  //  sayMyName();
    time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;
   int num = 500;
   int *ptr = new int(400);
   unique_ptr<int> ptr1 = ptr;
   cout<<*ptr1<<endl;
  return 0;
}
