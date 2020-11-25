#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include "Line.hpp"

const size_t SIDES = 2;

class Rectangle : public Shape {
private:
	Line _sides[SIDES];

public:
	Rectangle(size_t x0, size_t y0, size_t x1, size_t y1) :
		_sides{
			Line(x0, y0, x1, y0),
			Line(x0, y1, x1, y1)/*,
			Line(y0 - 1, x0 + 1, y1 - 1, x0 + 1),
			Line(y0 +5, x0 +1, y0+5 , x0+1 )*/
		}
	{
		/*_sides[2].Rotate(90);
		_sides[3].Rotate(90);*/
		
		//if (x1 < x0) {
		//	size_t aux_x = x0;
		//	size_t aux_y = y0;
		//	x0 = x1; y0 = y1; x1 = aux_x; y1 = aux_y;
		//}

		/*_position[0] = x0;
		_position[1] = y0;*/


	};

	void Scale(const float& FACTOR) {
		for (size_t i = 0; i < SIDES; i++)
			_sides[i].Scale(FACTOR);
	};

	void Plot(Image& IMAGE)
	{
		for (size_t i = 0; i < SIDES; i++)
			_sides[i].Plot(IMAGE);
	};

};

#endif

