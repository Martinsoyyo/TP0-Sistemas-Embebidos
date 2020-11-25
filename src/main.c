#include <stdio.h>
#include "image.h"
#include "line.h"
#include "rectangle.h"

#define MAX_IMG_NAME	255
#define N_ROWS			200
#define N_COLS			200
#define FRAMES			 72


int main(void)
{
	char img_name[MAX_IMG_NAME];

	const float delta_angle = 1.0f;
	const float delta_scale = 0.9995f;

	const size_t ROWS = 200;
	const size_t COLS = 20;

	float angle = 0.0f;
	float scale = 1;

	for (size_t idx = 0; idx < FRAMES; idx++) {
		image_t img;
		image_ctor(&img, N_ROWS, N_COLS);

		scale *= delta_scale;
		angle += delta_angle;

		line_t line1;
		line_t line2;
		rectangle_t rect1;

		line_ctor(&line1, 10, 10, 50, 50);
		line_ctor(&line2, 50, 50, 150, 100);
		rectangle_ctor(&rect1, 70, 70, 110, 89);


		line_rotate(&line1, angle);
		line_rotate(&line2, -angle);
		rectangle_rotate(&rect1, 2*angle);


		shape_plot(&line1.super, &img);
		shape_plot(&line2.super, &img);
		shape_plot(&rect1.super, &img);



		sprintf(img_name, "./images/img%.3d.txt", idx);
		image_to_file(&img, img_name);

		shape_dtor((shape_t*)&line1);
		shape_dtor((shape_t*)&line2);
		shape_dtor((shape_t*)&rect1);

		image_dtor(&img);
	}
};
