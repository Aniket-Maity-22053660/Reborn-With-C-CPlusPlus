#include<iostream>

using namespace std;

class Box{
  //void printVolume();
  double length;
  double width;
  double height;
public:
  void printVolume();
  void setLength(double length);
  void setWidth(double width);
  void setHeight(double height);
  Box operator+(Box box){
    Box obj;
    obj.length = this->length + box.length;
    obj.width = this->width + box.width;
    obj.height = this->height + box.height;
    return obj;
  }
};

void Box::setLength(double length){
  this->length = length;
}

void Box::setWidth(double width){
  this->width = width;
}

void Box::setHeight(double height){
  this->height = height;
}

void Box::printVolume(){
  cout<<"Volume: "<<length * width * height<<endl;
}

int main(){

  Box obj1, obj2;
  obj1.setLength(9.0);
  obj1.setWidth(8.0);
  obj1.setHeight(3.0);
  obj1.printVolume();
  obj2.setLength(5.0);
  obj2.setWidth(4.0);
  obj2.setHeight(7.0);
  obj2.printVolume();
  Box obj3 = obj1 + obj2;
  obj3.printVolume();
  return 0;
}
