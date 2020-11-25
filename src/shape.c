#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shape.h"
#include "image.h"

bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){

	me->position.x = position_x;
	me->position.y = position_y;

	if (!(me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*array->n_array))){
			return false;
		}

	me->array.n_array = array->n_array;

	for( int i=0; i < me->array.n_array; i++){
		me->array.coordinates[i] = array->coordinates[i];
	}

	return true;
}


void shape_dtor(shape_t *me)
{
	if (me->array.coordinates != NULL) free(me->array.coordinates);
}


bool shape_move(shape_t *me, uint32_t dx, uint32_t dy)
{
	me->position.x += dx;
	me->position.y += dy;

	return true;
}


bool shape_plot(shape_t *me, image_t *image)
{

	for(int i = 0; i < me->array.n_array; ++i){
		int x = me->array.coordinates[i].x + me->position.x;
		int y = me->array.coordinates[i].y + me->position.y;
		if( x < image->n_cols && y < image->n_rows){
			image_write(image, x, y, HIGH);
		}
	}
	return true;
}

bool shape_rotate(shape_t* me, float ANGLE) {
	//https://en.wikipedia.org/wiki/Rotation_matrix
	static const double DEG2RAD = 3.14159265 / 180;

	for (uint32_t i = 0; i < me->array.n_array; i++) {
		double x = me->array.coordinates[i].x;
		double y = me->array.coordinates[i].y;

		me->array.coordinates[i].x = (size_t)round(x * cos(ANGLE * DEG2RAD) - y * sin(ANGLE * DEG2RAD));
		me->array.coordinates[i].y = (size_t)round(x * sin(ANGLE * DEG2RAD) + y * cos(ANGLE * DEG2RAD));
	}
	return true;
}

