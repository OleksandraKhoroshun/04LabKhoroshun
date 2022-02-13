#pragma once

#include "Segment.h"

class Triangle {

private:
	static int _freeID;
	const int _myID;

	Point _a, _b, _c;
	mutable Segment * _ab, * _bc, * _ca;


public:
	Triangle(const double x1 = 0, const double y1 = 0,const double x2 = 1,
		const double y2 = 0,const double x3 = 0, const double y3 = 1);
	Triangle(const Point&, const Point&, const Point& c);
	Triangle(const Point& a, const Segment& s);
	Triangle(const Triangle&);
	~Triangle();

	Triangle& operator = (const Triangle&);

	Point& A();
	Point& B();
	Point& C();

	const Point& A() const;
	const Point& B() const;
	const Point& C() const;

   /* Segment& AB();
	Segment& BC();
	Segment& CA();*/

	const Segment& AB() const;
	const Segment& BC() const;
	const Segment& CA() const;

	double length_ab() const;
	double length_bc() const;
	double length_ca() const;
};

ostream& operator<<(ostream&, const Triangle&);
