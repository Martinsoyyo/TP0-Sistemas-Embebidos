#ifndef LINE_HPP
#define LINE_HPP

#include "Shape.hpp"

class Line : public Shape {
private:
	std::pair<size_t, size_t> _start;
	std::pair<size_t, size_t> _end;

	bool resize();

public:

	Line(size_t x0, size_t y0, size_t x1, size_t y1);

	void Scale(const float& FACTOR);

	float Length() const;

};

#endif