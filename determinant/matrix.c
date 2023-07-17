#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

// typedef struct Matrix_struct{
// 	int num_sides;
// 	float*** locpoint;
// }Matrix;

float** make_empty_matrix(int num_sides){
	int i = 0;
	float** matrix = (float**) calloc(num_sides, sizeof(float*));
	for (i = 0; i < num_sides; ++i) {
		matrix[i] = (float*) calloc(num_sides, sizeof(float));
	}
return matrix;
}

void fill_matrix_from_user_input(Matrix matrix, FILE* file){
	fscanf(file, " %d\n", &matrix.num_sides);
	for (int i = 0; i < matrix.num_sides; ++i) {
		for (int j = 0; j < matrix.num_sides; ++j) {
			fscanf(file, "%f", &(matrix.locpoint[i][j]));
		}
	}
}

void delete_matrix(Matrix matrix){
	for (int i = 0; i < matrix.num_sides; ++i) {
      free((matrix.locpoint)[i]);
    }
    free(matrix.locpoint);
    matrix.locpoint = NULL;
}

float Determinent_calculation(Matrix matrix){
	float determinent;
	// if (matrix.num_sides == 1){
	// 	return 0;
	// }
	if (matrix.num_sides == 2){
		determinent = (matrix.locpoint)[0][0] * (matrix.locpoint)[1][1] -
		(matrix.locpoint)[1][0] * (matrix.locpoint)[0][1];
	} else {
		for (int k = 0; k < matrix.num_sides; ++k){
			Matrix new_matrix = createByPop(matrix, k);
			determinent = determinent + pow((-1), k) * (matrix.locpoint)[0][k] *
			(Determinent_calculation(new_matrix));
			delete_matrix(new_matrix);
			}
	}
	return determinent;
}

// Matrix createByPop(Matrix matrix, int col_to_delete){
// 	Matrix new_matrix;
// 	new_matrix.locpoint = make_empty_matrix(matrix.num_sides - 1);
// 	new_matrix.num_sides = matrix.num_sides - 1;
//
//     for (int i = 1; i < matrix.num_sides; ++i){
// 		int y = 0;
// 		int x = i - 1;
// 		for (int j = 0; j < matrix.num_sides; ++j){
// 			if (j != col_to_delete)
// 			{
// 				(new_matrix.locpoint)[x][y] = (matrix.locpoint)[i][j];
// 			y += 1;
// 			}
// 		}
// 	}
// 	return new_matrix;
// }

Matrix createByPop(Matrix matrix, int k){
	Matrix new_matrix;
	new_matrix.locpoint = NULL;
	new_matrix.locpoint = make_empty_matrix(matrix.num_sides);
	new_matrix.num_sides = matrix.num_sides;
	// printf("new side: %d\n", new_matrix.num_sides);
	// printf("k: %d\n", k);

    for (int i = 0; i < matrix.num_sides; ++i){
		for (int j = 0; j < matrix.num_sides; ++j){
			(new_matrix.locpoint)[i][j] = (matrix.locpoint)[i][j];
		}
	}

	for (int i = 0; i < matrix.num_sides-1; ++i){
		(new_matrix.locpoint)[i] = (new_matrix.locpoint)[i+1];
		for(int j = k;j < matrix.num_sides - 1; ++j){
			(new_matrix.locpoint)[i][j] = (new_matrix.locpoint)[i][j+1];
		}
	}


	new_matrix.num_sides -= 1;
	new_matrix.locpoint = (float**)realloc(new_matrix.locpoint, (new_matrix.num_sides +1) * sizeof(float*));
	for (int i = 0; i < new_matrix.num_sides; ++i){
		(new_matrix.locpoint)[i] = (float*)realloc((new_matrix.locpoint)[i], (new_matrix.num_sides +1) * sizeof(float));
	}
	return new_matrix;
}
