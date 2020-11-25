#include "shape.h"
#include "rectangle.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>


bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y,
					uint32_t height, uint32_t width){


	coordinates_array_t array;
	int len = height*2 + width*2 - 4;

	if(!(array.coordinates = (coordinate_t *) malloc(len*sizeof(coordinate_t)))){
		return false;
	}
	array.n_array = len;

	for(int i = 0; i < height; ++i){
		array.coordinates[i].x = 0 + position_x;
		array.coordinates[i].y = i + position_y;
		array.coordinates[i + height].x = width - 1 + position_x;
		array.coordinates[i + height].y = i + position_y;
	}

	for(int i = 1; i < width - 1; ++i){
		array.coordinates[i - 1 + 2*height].x = i + position_x;
		array.coordinates[i - 1 + 2*height].y = 0 + position_y;
		array.coordinates[i - 1 + 2*height + width - 2].x = i + position_x;
		array.coordinates[i - 1 + 2*height + width - 2].y = height - 1 + position_y;
	}

	shape_ctor(&me->super, &array, position_x, position_y);
	free(array.coordinates);
	return true;
}


bool rectangle_rotate(rectangle_t *me, float angle){

	 shape_rotate(&me->super, angle);

	 return true;
}

bool rectangle_scale(rectangle_t *me, float factor){

	int len = me->super.array.n_array;

	for(int i = 0; i < len; ++i){
		double x = me->super.array.coordinates[i].x;
		double y = me->super.array.coordinates[i].y;

		x = (x - me->super.position.x) * factor;
		y = (y - me->super.position.y) * factor;

		x = x + me->super.position.x;
		y = y + me->super.position.y;

		me->super.array.coordinates[i].x = round(x);
		me->super.array.coordinates[i].y = round(y);
	}

	me->height= round(me->height * factor);
	me->width = round(me ->width * factor);

	return true;
}




uint32_t rectangle_get_area(rectangle_t *me){
	return me->height * me->width;
}
