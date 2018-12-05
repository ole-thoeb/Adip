#include <stdio.h>
#include <stdlib.h>


struct MatrixImp{
	int sizeY;
	int sizeX;
	double **values;
};

typedef struct MatrixImp* Matrix;

Matrix Matrix_new(int sizeX, int sizeY){
	Matrix m = malloc(sizeof(struct MatrixImp));
	m->sizeX = sizeX;
	m->sizeY = sizeY;
	m->values = malloc(sizeof(double*) * sizeX);
	for(size_t i = 0; i < sizeX; i++){
		m->values[i] = malloc(sizeof(double) * sizeY);
	}
	return m;
}

void Matrix_delete(Matrix m){
	for(size_t i = 0; i < m->sizeX; i++){
		free(m->values[i]);
	}
	free(m->values);
	free(m);
}

void Matrix_print(Matrix m){
	for(size_t i = 0; i < m->sizeY; i++){
		for(size_t j = 0; j < m->sizeX; j++){
			printf("%lf, ", m->values[j][i]);
		}
		putchar('\n');
	}
	putchar('\n');
}

Matrix Matrix_add(Matrix m1, Matrix m2){
	if(m1->sizeX != m2->sizeY) return NULL;
	Matrix c = Matrix_new(m2->sizeX, m1->sizeY);
	
	for(size_t i = 0; i < c->sizeX; i++){
		for(size_t j = 0; j < c->sizeY; j++){
			double sum = 0;
			for(size_t k = 0; k < m1->sizeX; k++){
				sum += m1->values[k][j] * m2->values[i][k];
			}
			c->values[i][j] = sum;
		}
	}
	return c;
}

int main(int argc, char const *argv[]){
	Matrix m1 = Matrix_new(2, 3);
	m1->values[0][0] = 1.0;
	m1->values[0][1] = 2.0;
	m1->values[0][2] = 3.0;
	m1->values[1][0] = 4.0;
	m1->values[1][1] = 5.0;
	m1->values[1][2] = 6.0;
	Matrix_print(m1);

	Matrix m2 = Matrix_new(3, 2);
	m2->values[0][0] = 1.0;
	m2->values[0][1] = 2.0;
	m2->values[1][0] = 3.0;
	m2->values[1][1] = 4.0;
	m2->values[2][0] = 5.0;
	m2->values[2][1] = 6.0;
	Matrix_print(m2);

	Matrix c = Matrix_add(m1, m2);
	if(!c) puts("fehler");
	else Matrix_print(c);
	Matrix_delete(m1);
	Matrix_delete(m2);
	Matrix_delete(c);
	return 0;
}
