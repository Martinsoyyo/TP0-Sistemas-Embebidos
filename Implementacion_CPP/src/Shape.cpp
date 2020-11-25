#include "Shape.hpp"

float Shape::shape_distance_from(const Shape& OTHER) const {
	auto x = _position[0] - OTHER._position[0];
	auto y = _position[1] - OTHER._position[1];
	return sqrt(x * x + y * y);
};

Shape::Shape() { memset(this, 0, sizeof(Shape)); }

Shape::Shape(std::pair<size_t, size_t>* POINTS,
	const size_t NELEM,
	const uint32_t& POSX,
	const uint32_t& POSY) :_nelem(NELEM)
{

	_position[0] = POSX;
	_position[1] = POSY;

	_points = new std::pair<size_t, size_t>[_nelem];

	if (_points == 0) return;
	for (size_t i = 0; i < _nelem; i++) _points[i] = POINTS[i];
};

Shape::~Shape() {
	if (_points != 0 && _nelem > 1)  delete[] _points;
};


void Shape::Move(int dx, int dy) {
	_position[0] += dx;
	_position[1] += dy;
};

void Shape::Rotate(const float& ANGLE) {
	//https://en.wikipedia.org/wiki/Rotation_matrix

	static const double DEG2RAD = 3.14159265 / 180;

	for (size_t i = 0; i < _nelem; i++) {
		double x = _points[i].first;
		double y = _points[i].second;

		_points[i].first  = size_t(round(x * cos(ANGLE * DEG2RAD) - y * sin(ANGLE * DEG2RAD) ));
		_points[i].second = size_t(round(x * sin(ANGLE * DEG2RAD) + y * cos(ANGLE * DEG2RAD) ));
	};
};

void Shape::Plot(Image& IMAGE) const  {
	for (size_t i = 0; i < _nelem; ++i) {
		auto x = _points[i].first +_position[0];
		auto y = _points[i].second +_position[1];
		if (x < IMAGE.nfil && y < IMAGE.ncol) 
			IMAGE.Image_Write(1, x, y);
	}
};