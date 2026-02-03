#include<iostream>
#include<memory>

using namespace std;

class Shape{
  float length, breadth, height;
  static int cnt;
public: 
  Shape(){
    cnt++;
    cout<<"Shape Class instance created: "<<cnt<<endl;
  }
  void setter(float, float, float);
  void printVolume();
  
};

int Shape::cnt = 0;

void Shape::setter(float length, float breadth, float height){
  this->length = length;
  this->breadth = breadth;
  this->height = height;
}

void Shape::printVolume(){
  printf("Volume of the shape: %.2f\n", (this->length * this->breadth * this->height));
}

int main(){
  unique_ptr<Shape[]> obj = make_unique<Shape[]>(2);
     obj[0].setter(150.90, 260.13 , 490.51);
     obj[1].setter(340.12, 239.93, 184.80);
     cout<<"Volume of shape-1: ";
     obj[0].printVolume();
     cout<<"Volume of shape-2: ";
     obj[1].printVolume();
  return 0;
}
