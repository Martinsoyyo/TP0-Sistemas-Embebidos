#ifndef RECTANGLE_H
#define RECTANGLE_H 

#include "shape.h"
#include <stdint.h>

/* Estructura principal que representa la clase "rectÃ¡ngulo" */
typedef struct {
	shape_t super; 			// Clase de la cual se hereda
	uint32_t height;		// Altura del rectÃ¡ngulo
	uint32_t width;			// Ancho del rectÃ¡ngulo
	float rotation_angle;	// Ã�ngulo en el cual se encuentra rotada la figura
} rectangle_t;


/** 	@brief: Contructor del objeto "rectÃ¡ngulo"
*		@params: recibe el puntero al objeto, la posiciÃ³n en el espacio (posiciÃ³n en x e y), la altura y el ancho del rectÃ¡ngulo
*		@return: Devuelve verdadero sii encontrÃ³ memoria para guardar el objeto.
**/
bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y, 
					uint32_t height, uint32_t width);

/** 	@brief: Rota al rectÃ¡ngulo un cierto Ã¡ngulo.
*		@params: recibe el puntero al objeto y el valor en radianes a rotar.
*		@return: Devuelve verdadero si la operaciÃ³n resultÃ³ exitosa.
**/
bool rectangle_rotate(rectangle_t *me, float angle);


/** 	@brief: Devuelve el Ã¡rea del rectÃ¡ngulo.
*		@params: recibe el puntero al objeto.
*		@return: Devuelve el valor del Ã¡rea.
**/

bool rectangle_scale(rectangle_t *me, float factor);


uint32_t rectangle_get_area(rectangle_t *me);



#endif
