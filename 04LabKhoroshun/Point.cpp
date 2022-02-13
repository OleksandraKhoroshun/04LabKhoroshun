// Point.cpp : This file contains the realization of all functions and methods of class Point. 
// Khoroshun O. 14/01/2022

#include "Point.h"

//counting IDs
int Point::_freeID = 0;

//constructor for Point accepts coordinates
//in debug mode prints a message about Point creation
Point::Point(double x, double y) :
	_x(x),
	_y(y),
	_pointID(++_freeID)
{
#ifdef NDEBUG
	cout << "Point " << _pointID << " " << *this << " created." << endl;
#endif
	return;
}

//constructor for Point accepts Point 
//in debug mode prints a message about Point copying
Point::Point(const Point& u) :
	_x(u._x),
	_y(u._y),
	_pointID(++_freeID)

{
#ifdef NDEBUG
	cout << "Point " << _pointID << " " << *this << " created as a copy of Point " << u.getID() << u << endl;
#endif
	return;
}

//deleting Point
//prints a message about Point deletion
Point::~Point()
{
#ifdef NDEBUG
	cout << "Point " << _pointID << " " << *this << " deleted." << endl;
#endif
	return;
}

//operator = accepts Point
//returns Point
Point& Point::operator=(const Point& u)
{
	_x = u._x;
	_y = u._y;
	return *this;

}

//selector-modifier x
//returns x
double& Point::x()
{
	return _x;
}

//selector-modifier y
//returns y
double& Point::y()
{
	return _y;
}

//const selector x
//returns x
const double& Point::x()const
{
	return _x;
}

//const selector y
//returns y
const double& Point::y()const
{
	return _y;
}

//const selector ID
//returns Point ID
const int Point::getID()const
{
	return _pointID;
}

//returns number of Points total
int Point::amount()
{
	return _freeID;
}

//returns coordinates of Point 
ostream& operator<<(ostream& os, const Point& u)
{
	return os << '(' << u.x() << ',' << u.y() << ')';
}

//adds Point v to Point u
//returns new Point
const Point operator+ (const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());

}

//adds Point v to Point u
//returns Point u
Point& operator+=(Point& u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

//returns true if points are equal, false if not
bool operator==(const Point& u, const Point& v)
{
	return u.x() == v.x() && u.y() == v.y() ? true : false;
}

//returns false if points are equal, true if not
bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}



