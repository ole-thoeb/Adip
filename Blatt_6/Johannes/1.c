//Multiplikation zweier Matrizzen
#include<stdio.h>

/*
1-dimensionales Array zur Darstellung der Matrix. getindex zur Umrechnnug des richtigen index.
Beipiel: 3X4-Matrix A, also col_len = 4 -> Wert [2,2] der Matrix = A[2+2*4] = A[10]

ACHTUNG: Matrix-Indizes beginnen hier bei 0!
			A[0,1] existiert, A[3,3] nicht!
*/

int getindex(int row, int col, int col_len){
	int erg = row + col*col_len;
	return erg;
}

void printarray(double *m, int rowmax, int colmax){
		for(int col = 0; col < colmax; col++){
		printf("\n");
		for(int row = 0; row < rowmax; row++){			
			printf("\n [%i, %i] = %lf", row, col, m[getindex(row, col, colmax)]);
		}
	}	
}

void fillarray(double *m, int rowmax, int colmax){
	printf("\n");
	for(int col = 0; col < colmax; col++){
		for(int row = 0; row < rowmax; row++){
			double input = 0;
			printf("\n Wert fuer [%i, %i]: ", row, col);
			scanf("%lf", &input);
			m[getindex(row, col, colmax)] = input;	
		}
	}	
}

//Anmerkung: Aus Faulheit überall int statt unsigned für die Zeilen-/Spaltenanzahl. Bitte sinnvoll verwenden!
int main(void){
	int i = 0, j = 0, k = 0, l = 0;
	printf("\nZeilenanzahl i der ersten Matrix: ");
	scanf("%i", &i);
	printf("\nSpaltenanzahl j der ersten Matrix: ");
	scanf("%i", &j);
	printf("\nZeilenanzahl k der zweiten Matrix: ");
	scanf("%i", &k);
	printf("\nSpaltenanzahl l der zweiten Matrix: ");
	scanf("%i", &l);
	
	//Füllen der Matrizzen (by reference)
	//erste Matrix
	double *A;
	A = (double*) malloc(i*j*sizeof(double));
	fillarray(A, i, j);
	printarray(A, i, j);
	
	//zweite Matrix
	double *B;
	B = (double*) malloc(k*l*sizeof(double));
	fillarray(B, k, l);
	printarray(B, k, l);
	
	//Ergebnis-Matrix	
	double *C;
	C = (double*) malloc(i*l*sizeof(double));
	
	if(j != k){
		printf("\n\nSpalten j von A ungleich Zeilen k von B");
	} else {
		printf("\n\nErgebnis:");

		for(int row = 0; row < i; row++){
		printf("\n");
			for(int col = 0; col < l; col++){
				C[getindex(row, col, l)] = 0;
				//Formel für Matrizzen-Multiplikation
				for(int index = 0; index < k; index++){
					C[getindex(row, col, l)] += A[getindex(row, index, j)]*B[getindex(index, col, l)];					
				}				
			}
		}
		printarray(C, i, l);		
	}
	
	free(A);
	free(B);
	free(C);
	
	return 0;
}