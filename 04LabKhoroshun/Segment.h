#pragma once
//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//Developed by Khoroshun O.
//at 1/29/2022
//Version 1.0

//*******************************************

#include "Point.h"

// Class of segments
class Segment
{
private:
	// Means of accounting for segments
	static int _freeID;
	const int _myId;
	// The starting point of the segment
	Point _a;
	// End point of the segment
	Point _b;

public:
	// Constructors of segments
// 1) by the coordinates of its ends
	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);
	// 2) by the points of beginning and end
	Segment(const Point& start, const Point& end);
	// 3) copying constructor
	Segment(const Segment&);
	// Destructor
	~Segment();

	// Assignment
	Segment& operator=(const Segment&);
	// Point selectors
	const Point& start() const;
	const Point& end() const;
	// Selectors-modifiers of points
	Point& start();
	Point& end();
	// Point coordinates selectors
	const double& startX() const;
	const double& startY() const;
	const double& endX() const;
	const double& endY() const;
	// Selectors-modifiers of coordinates of points
	double& startX();
	double& startY();
	double& endX();
	double& endY();
	// Calculating the length of the segment
	double length() const;
	// Calculating the distance from segment to point
	double distance(const Point&) const;
	// Selector ID
	const int getID() const;
};

ostream& operator<<(ostream&, const Segment&);
