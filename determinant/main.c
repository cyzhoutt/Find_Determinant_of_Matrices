#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main(int argc, char** argv){
	int num_sides = 0;

	Matrix matrix;
	matrix.num_sides = num_sides;


	FILE* file = fopen(argv[1], "r");
	if (file == NULL) {
		fclose(file);
		return 0;
	}else{
	fscanf(file, " %d", &matrix.num_sides);
	matrix.locpoint = make_empty_matrix(matrix.num_sides);
	fill_matrix_from_user_input(matrix, file);
	fclose(file);

	float determinent = Determinent_calculation(matrix);

	delete_matrix(matrix);

	printf("The determinant is %.2f.", determinent);

	return 0;
	}
}
