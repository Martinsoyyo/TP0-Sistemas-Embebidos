#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <stdint.h>
#include <utility> 
#include <math.h>
#include <iostream>
using namespace std;

#include "Image.hpp"

class Shape {
protected:
	size_t					   _position[2];
	std::pair<size_t, size_t>* _points;
	size_t					   _nelem;

	float shape_distance_from(const Shape& OTHER) const;

	friend class Rectangle;

public:

	Shape();

	Shape(std::pair<size_t, size_t>* POINTS, const size_t NELEM, const uint32_t& POSX, const uint32_t& POSY);

	~Shape();

	void Move(int dx, int dy);

	void Rotate(const float& ANGLE);

	void Plot(Image& IMAGE) const;
};


#endif