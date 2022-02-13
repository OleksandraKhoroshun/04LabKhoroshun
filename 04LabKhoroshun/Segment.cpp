// Segment.cpp : This file contains the realization of all functions and methods of class Segment. 
// Khoroshun O. 29/01/2022

#include "Segment.h"
#include <cmath>
#include <cassert>
using namespace std;

//counting IDs
int Segment::_freeID(0);

Segment::Segment(const double x1, const double y1,
	const double x2, const double y2) :
	_a(x1, y1),
	_b(x2, y2),
	_myId(++_freeID)
{
#ifdef NDEBUG
	cout << "Segment " << _myId << " " << *this << " created." << endl;
#endif
	return;
}

Segment::Segment(const Point& start, const Point& end) :
	_a(start),
	_b(end),
	_myId(++_freeID)
{
#ifdef NDEBUG
	cout << "Segment " << _myId << " " << *this << " created." << endl;
#endif
	return;
}

Segment::Segment(const Segment& s) :
	_a(s._a),
	_b(s._b),
	_myId(++_freeID)
{
#ifdef NDEBUG
	cout << "Segment " << _myId << " " << *this << " copied." << endl;
#endif
	return;
}

Segment::~Segment()
{
#ifdef NDEBUG
	cout << "Segment " << _myId << " " << *this << " deleted." << endl;
#endif
	return;
}

Segment& Segment::operator=(const Segment& s)
{
	_a = s.start();
	_b = s.end();
	return *this;
}

const Point& Segment::start() const
{
	return _a;
}

const Point& Segment::end() const
{
	return _b;
}

Point& Segment::start()
{
	return _a;
}

Point& Segment::end()
{
	return _b;
}

const double& Segment::startX() const
{
	return _a.x();
}

const double& Segment::startY() const
{
	return _a.y();
}

const double& Segment::endX() const
{
	return _b.x();
}

const double& Segment::endY() const
{
	return _b.y();
}

double& Segment::startX()
{
	return _a.x();
}

double& Segment::startY()
{
	return _a.y();
}

double& Segment::endX()
{
	return _b.x();
}

double& Segment::endY()
{
	return _b.y();
}

double length_calc(const Point& a, const Point& b)
{
	return sqrt((b.x() - a.x()) * (b.x() - a.x()) + (b.y() - a.y()) * (b.y() - a.y()));
}

double Segment::length() const
{
	return length_calc(start(), end());
}

#ifndef NDEBUG
//another way to calculate distance
//used for assert
double distance_calc(const Point& c, const Point& a, const Point& b)
{
	double ab = length_calc(a, b);
	double ac = length_calc(a, c);
	double bc = length_calc(b, c);

	double res = 0;

	//calculating cosine
	double cos_cab = ((c.x() - a.x()) * (b.x() - a.x()) + (c.y() - a.y()) * (b.y() - a.y())) / ac * ab;
	double cos_cba = ((c.x() - b.x()) * (a.x() - b.x()) + (c.y() - b.y()) * (a.y() - b.y())) / bc * ab;

	if (cos_cab <= 0) res = ac;
	else if (cos_cba <= 0) res = bc;
	else {
		//if angles are acute
		double A = a.y() - b.y();
		double B = a.x() - b.x();
		double C = a.y() * b.x() - b.y() * a.x();
		res = (A * c.x() + B * c.y() + C) / sqrt(A * A + B * B);
	}

	return res;
}
#endif

double Segment::distance(const Point& c) const
{
	double ab = length();
	double ac = length_calc(start(), c);
	double bc = length_calc(end(), c);

	double res = 0;
	//if angles are not acute
	if (bc * bc >= ab * ab + ac * ac) res = ac;
	else if (ac * ac >= ab * ab + bc * bc) res = bc;
	else {
		//Heron's formula:
		double p = (ab + ac + bc) / 2;
		double S = sqrt(p * (p - ab) * (p - bc) * (p - ac));
		res = 2 * S / ab;
	}
#ifndef NDEBUG
	//in order to test the correctness of methods I create a test value
	//and round it and the original result, because machine arithmetic is not perfect
	//and the precision of double is only 15
	double test_val = distance_calc(c, start(), end());
	test_val = round(test_val * 1000000000000000.0) / 1000000000000000.0;
	res = round(res * 1000000000000000.0) / 1000000000000000.0;
	assert(res == test_val);
#endif
	return res;

}

const int Segment::getID() const
{
	return _myId;
}

ostream& operator<<(ostream& os, const Segment& s)
{
	return os << s.start() << s.end();
}