#include<iostream>
#include<cstring>

using namespace std;

class Car{
protected:
  char name[30];
public:
  Car(){
    strcpy(name, "BMW");
  };
  friend void printName(Car*);
};

void printName(Car* car){
  cout<<"Name of the Car: "<<car->name<<endl;
}

class Box{

  char name[20];
public:
  Box(){
    strcpy(name, "King Star");
  }
  void getName();
  friend void printName(Box);
};

void Box::getName(){
  cout<<"Box name: "<<this->name<<endl;
}

void printName(Box box){
  cout<<"Name of the box: "<<box.name<<endl;
}

class Main: virtual private Box, private Car{
public:
  Box* box1;
  Car* car1;
  Main(){
    car1 = new Car();
    box1 = new Box();
  }
  void getInfo();
  Box* getBoxRef();
  Car* getCarRef();
  
};

void Main::getInfo(){
  box1->getName();
  printName(car1);
}

Box* Main::getBoxRef(){
  return box1;
}

Car* Main::getCarRef(){
  return car1;
}

int main(){

  Main main;
  main.getInfo();
  main.getBoxRef()->getName();
  return 0;
}
