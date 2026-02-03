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
  Shape operator+(Shape);  
};

int Shape::cnt = 0;

Shape Shape::operator+(Shape shape){
  Shape myShape;
  myShape.length = this->length + shape.length;
  myShape.breadth = this->breadth + shape.breadth;
  myShape.height = this->height + shape.height;
  return myShape;
}

void Shape::setter(float length, float breadth, float height){
  this->length = length;
  this->breadth = breadth;
  this->height = height;
}

void Shape::printVolume(){
  printf("%.2f\n", (this->length * this->breadth * this->height));
}

int main(){
  unique_ptr<Shape[]> obj = make_unique<Shape[]>(3);
     obj[0].setter(150.90, 260.13 , 490.51);
     obj[1].setter(340.12, 239.93, 184.80);
     cout<<"Volume of shape-1: ";
     obj[0].printVolume();
     cout<<"Volume of shape-2: ";
     obj[1].printVolume();
     cout<<"Adding two shape objects:- "<<endl;
     obj[2] = obj[0] + obj[1];
     cout<<"Volume of the new shape: ";
     obj[2].printVolume();
  return 0;
}
