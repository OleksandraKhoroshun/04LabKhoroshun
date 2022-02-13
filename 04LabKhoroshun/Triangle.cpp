#include "Triangle.h"
#include <cmath>
#include <cassert>
using namespace std;

//counting IDs
int Triangle::_freeID(0);

Triangle::Triangle(const double x1 , const double y1 , const double x2 ,
	const double y2, const double x3 , const double y3 ):
	_a(x1,y1),
	_b(x2,y2),
	_c(x3,y3),
	_myID(_freeID++)
{
#ifdef NDEBUG
	cout << "Triangle " << _myID << " " << *this << " created." << endl;
#endif
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c):
	_a(a),
	_b(b),
	_c(c),
	_myID(_freeID++)
{
#ifdef NDEBUG
	cout << "Triangle " << _myID << " " << *this << " created." << endl;
#endif
}

Triangle::Triangle(const Point& a, const Segment& s):
	_a(a),
	_b(s.start()),
	_c(s.end()),
	_myID(_freeID++)
{
#ifdef NDEBUG
	cout << "Triangle " << _myID << " " << *this << " created." << endl;
#endif
}

Triangle::Triangle(const Triangle& t):
	_a(t.A()),
	_b(t.B()),
	_c(t.C()),
	_myID(_freeID++)
{
#ifdef NDEBUG
	cout << "Triangle " << _myID << " " << *this << " copied." << endl;
#endif
}

Triangle::~Triangle() {
	if (_ab != nullptr) delete _ab;
	if (_bc != nullptr) delete _bc;
	if (_ca != nullptr) delete _ca;

#ifdef NDEBUG
	cout << "Triangle " << _myID << " " << *this << " deleted." << endl;
#endif
}

Triangle& Triangle::operator = (const Triangle& t) {
	if (this == &t) 
		return *this;
	_a = t._a;
	_b = t._b;
	_c = t._c;

	return *this;
}

const Point& Triangle::A() const {
	return _a;
}

const Point& Triangle::B() const {
	return _b;
}

const Point& Triangle::C() const {
	return _c;
}

const Segment& Triangle::AB() const {
	if (_ab == 0)
		_ab = new Segment(_a, _b);
	return *_ab;
}

const Segment& Triangle::BC() const {
	if (_bc == 0)
		_bc = new Segment(_b, _c);
	return *_bc;
}

const Segment& Triangle::CA() const {
	if (_ca == 0)
		_ca = new Segment(_c, _a);
	return *_ca;
}

double Triangle::length_ab() const {
	return AB().length();
}

double Triangle::length_bc() const {
	return BC().length();
}

double Triangle::length_ca() const {
	return CA().length();
}

ostream& operator<<(ostream& os, const Triangle& t) {
	return os << t.A() << t.B() << t.C();
}