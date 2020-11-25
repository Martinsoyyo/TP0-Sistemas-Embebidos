#include "Image.hpp"

Image::Image(const size_t& NFIL, const size_t& NCOL) :nfil(NFIL), ncol(NCOL) {
	_ptr = new size_t * [NFIL];
	for (size_t i = 0; i < NFIL; i++) _ptr[i] = new size_t[NCOL];

	for (size_t i = 0; i < NFIL; i++)
		for (size_t j = 0; j < NCOL; j++)
			_ptr[i][j] = 0;
};

Image::~Image() {
	for (size_t i = 0; i < ncol; i++) delete[] _ptr[i];
	delete _ptr;
};

void Image::Image_Write(const size_t& DAT, const size_t F, const size_t C) {
	assert(F <= nfil && C <= ncol);
	_ptr[F][C] = DAT;
}

size_t Image::Image_Read(const size_t F, const size_t C) {
	assert(F <= nfil && C <= ncol);
	return(_ptr[F][C]);
};

void Image::Image_To_File(const char* FILENAME) {
	FILE* filename_ptr;

	filename_ptr = fopen(FILENAME, "w+");
	if (filename_ptr) {
		fprintf(filename_ptr, "P1\n%d %d\n", ncol, nfil);
		for (size_t i = 0; i < nfil; i++) {
			for (size_t j = 0; j < ncol; j++) {
				fprintf(filename_ptr, "%d ", Image_Read(i, j));
			}
			fprintf(filename_ptr, "\n");
		}
		fclose(filename_ptr);
	};
};