#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "shape.h"
#include "line.h"


bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){

	coordinates_array_t array;
	//me->super.position.x = x1;
	//me->super.position.y = y1;

	me->start.x = 0;
	me->start.y = 0;

	me->end.x = x2-x1;
	me->end.y = y2-y1;

   	float m = (float)y2 / ((float)x2);
	float b = 0;


	int len = abs(x2-x1)+1;

	if(!(array.coordinates = (coordinate_t *) malloc(len*sizeof(coordinate_t)))){
		return false;
	}
	array.n_array = len;
	for(int i = 0; i < len; i++){
		if(x1 < x2){
			array.coordinates[i].x = +i;
			array.coordinates[i].y = m * i + b;
		} else {
			array.coordinates[i].x = -i;
			array.coordinates[i].y = -m * i + b;

		}
	}

	shape_ctor(&me->super, &array, x1, y1);
	free(array.coordinates);

	return true;
}

bool line_rotate(line_t *me, float angle){
	shape_rotate(&me->super, angle);
    return true;
}


bool line_scale(line_t* me, float factor) {

	return true;
};


float line_get_lenght(line_t *me)
{
	return sqrt( ( ((me->start.x)-(me->end.x)) * ((me->start.x)-(me->end.x)) ) + ( ((me->start.y)-(me->end.y)) * ((me->start.y)-(me->end.y)) ) );
}


