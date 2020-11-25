#include "Image.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


int main(void) 	
	{
		const size_t frames = 72;
		const float delta_angle = 8.0f;
		const float delta_scale = 0.95f;

		const size_t ROWS = 200;
		const size_t COLS = 200;

		char img_name[255];
		size_t count = 0;

		float angle = 0.0f;
		float scale = 1;

		for (size_t idx = 0; idx < frames; idx++) {
			angle += delta_angle;

			if (scale > 0.002) {
				scale -= 1 / float(frames);
			};

			Image img(ROWS, COLS);
			{

				Line line1(10, 20, 30, 40);
				line1.Move(idx, 2*idx);
				line1.Scale(scale);
				line1.Rotate(angle);
				line1.Plot(img);

				Line line2(30, 20, 130, 140);
				line2.Move(idx, idx);
				line2.Scale(0.2*scale);
				line2.Rotate(-2*angle);
				line2.Plot(img);

				Line line3(130, 120, 200, 200);
				line3.Move(-1*idx, -1*idx);
				line3.Scale(0.2 * scale);
				line3.Rotate(-2 * angle);
				line3.Plot(img);
			}

			sprintf(img_name, "image//img%.3d.txt", count++);
			img.Image_To_File(img_name);
			//cout << img_name << endl;
		}
		//system("pause");
		return 0;
	}

