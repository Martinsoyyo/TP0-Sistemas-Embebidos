#include "Line.hpp"

//Line::Line() { memset(this, 0, sizeof(Line)); }

Line::Line(size_t x0, size_t y0, size_t x1, size_t y1) :
	_start(x0, y0), _end(x1, y1)
{
	if (Length() > 1) {
		_nelem = abs(float(_start.first - _end.first)) + 1;

		_position[0] = x0;
		_position[1] = y0;

		_start = std::pair<size_t, size_t>(0, 0);
		_end   = std::pair<size_t, size_t>(x1 - x0, y1 - y0);

		resize();
	};
};

void Line::Scale(const float& FACTOR) 
{
	if (Length() > 1) {
		_end.first = _end.first * FACTOR;
		_end.second = _end.second * FACTOR;
		resize();
	}
};

float Line::Length() const 
{
	auto& x0 = _start.first;
	auto& y0 = _start.second;
	auto& x1 = _end.first;
	auto& y1 = _end.second;

	return sqrt(((x0 - x1) * (x0 - x1)) + ((y0 - y1) * (y0 - y1)));
};

bool Line::resize()
{
	if (_points != 0) delete[] _points;

	auto& x1 = _start.first;
	auto& y1 = _start.second;
	auto& x2 = _end.first;
	auto& y2 = _end.second;

	float m = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
	float b = (float)y1 - ((((float)y2 - (float)y1)) / ((float)x2 - (float)x1)) * (float)x1;

	_nelem = abs(float(x2 - x1)) + 1;
	if (_nelem > 1) {
		_points = new std::pair<size_t, size_t>[_nelem];
		if (_points == 0) return false;

		for (size_t i = 0; i < _nelem; i++) {
			(x1 < x2) ?
				_points[i] = std::pair<size_t, size_t>(x1 + i, m * (x1 + i) + b) :
				_points[i] = std::pair<size_t, size_t>(x1 - i, m * (x1 - i) + b);
		}
	};
}
