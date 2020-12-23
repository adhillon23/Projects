#ifndef _POINT_HPP
#define _POINT_HPP

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// the class represents a point in 2D and its name
class Point
{
   private:
   int m_x;
   int m_y;
   string m_name;

   public:
   //default constructor
   Point(){}
  
   //copy constructor
   Point(int x, int y, string name)
   : m_x(x), m_y(y), m_name(name) {}
    
   //copy constructor
   Point(const Point& other)
   : m_x(other.m_x), m_y(other.m_y), m_name(other.m_name) {}
   
   int getX() const {return m_x;}

   void setX(int x) {m_x=x;}

   int getY() const {return m_y;}
   
   void setY(int y) {m_y=y;}
    
   void setName(string new_name){m_name = new_name;}    
	
   string getName() const {return m_name;}

   float getDistance(const Point &other); 

   string toString() const;

   void printPoint() const;

   // used for printing Point using << operator. For example:
   // Point p(1,2,"A");
   // cout << p << endl;
   friend ostream& operator<<(ostream &os, const Point &p);

};


#endif
