#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <stdbool.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <cassert>


class Image {
private:
	size_t** _ptr;

protected:
	size_t nfil;
	size_t ncol;

public:
	friend class Shape;

	Image(const size_t& NFIL, const size_t& NCOL);

	~Image();

	void Image_Write(const size_t& DAT, const size_t F, const size_t C);

	size_t Image_Read(const size_t F, const size_t C);

	void Image_To_File(const char* FILENAME);
};

#endif
