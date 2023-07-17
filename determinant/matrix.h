#ifndef MATRIX_H
	#define MATRIX_H
	    #include <stdio.h>
	    #include <stdlib.h>
		#include <math.h>

		typedef struct Matrix_struct{
			int num_sides;
			float** locpoint;
		}Matrix;

float** make_empty_matrix(int num_sides);
void fill_matrix_from_user_input(Matrix matrix, FILE* file);
void delete_matrix(Matrix matrix);
float Determinent_calculation(Matrix matrix);
Matrix createByPop(Matrix matrix, int k);

#endif
