
/* CSE109
   Spring 2015
   Emilio Arellano
   A driver program for testing the functionality of class Point
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
  Class Point implements the abstract data type (ADT) for a three
  dimensional point with integer components. Keeping with the usual
  mathematical notation, the first dimension is labeled x, the second
  dimension y, and the third dimension z
*/
class Point{
public:
  static const int X=0,Y=1,Z=2; //constants to identify the x,y, and z components
private:
  int x,y,z;  //the three components

  //If b is true, do nothing. If b is false, print an error message
  //with body 'mess' and exit
  void check(bool b,string mess)const;
public:
  Point(int a=0,int b=0,int c=0); //x<-a, y<-b, z<-c
  Point(const Point & pt);  //faithfully copy pt
  ~Point();  //does nothing, but we get in the habit of including the
	     //destructor so that we don't forget it when it is needed
  Point & operator()(int pt[]);//change the Point so that x<-pt[0],
			       //y<-pt[1], z<-pt[2]
  // returns the addres at which a sepecific cordinate resides
  int & operator [](int cordinate);
  
  // this method add the values of both point to create a new one with the new values
  Point  operator + (const Point &p);
  
  //Display the Point in the form (x,y,z)
  friend ostream & operator<<(ostream &out,const Point &);
};

int main(){
  Point a,b(1),c(2,5),d(3,4,5),e(d);
  int h[]={42,43,44};
  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
  a[Point::Z]=42;
  cout<<a<<endl;
  //the next line is a mind-bender: call a(h) and then apply the
  //operator [] to change the X component of the changed Point
  a(h)[Point::X]=99;
  cout<<a<<endl;
  cout<<a<<" + "<<d<<" = "<<(a+d)<<endl;
}
/*EXPECTED OUTPUT
  (0, 0, 0} (1, 0, 0} (2, 5, 0} (3, 4, 5} (3, 4, 5}
  (0, 0, 42}
  (99, 43, 44}
  (99, 43, 44} + (3, 4, 5} = (102, 47, 49}
*/

void Point::check(bool b,string mess)const{
  if(!b){
    cerr<<"ERROR[Point]"<<mess<<endl;
    exit(1);
  }
}
  
Point::Point(int a,int b,int c):x(a),y(b),z(c){}
   
Point::Point(const Point & p):x(p.x),y(p.y),z(p.z){}
 
Point::~Point(){}
 
Point & Point::operator()(int pt[]){
  x=pt[0];
  y=pt[1];
  z=pt[2];
  return *this;
}
 
ostream & operator<<(ostream &out,const Point &p){
  out<<"("<<p.x<<", "<<p.y<<", "<<p.z<<"}";
  return out;
}

int & Point:: operator [](int cordinate){
  check(cordinate < 3 && cordinate > -1,"Error: Point opperator []: invalid Cordinate");
  switch(cordinate){
  case 0: return x;
  case 1: return y;
  case 2: return z;
  default: exit(1);
  }
}

Point  Point:: operator + (const Point &p){
  int x1 = x + p.x;
  int y1 = y + p.y;
  int z1 = z + p.z;
  return Point(x1,y1,z1);
}

/*EXPECTED OUTPUT
  (0, 0, 0} (1, 0, 0} (2, 5, 0} (3, 4, 5} (3, 4, 5}
  (0, 0, 42}
  (99, 43, 44}
  (99, 43, 44} + (3, 4, 5} = (102, 47, 49}
*/
