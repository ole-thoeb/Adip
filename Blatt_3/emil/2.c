#include <stdio.h>

double aMittel(double *arg, int length){
	double sum = 0;
	for(int i = 0; i < length; i++){
		sum += arg[i];
	}
	return sum / length;
}

double varianz(double *arg, int length){
	double sum = 0;
	double mittel = aMittel(arg, length);
	for(int i = 0; i < length; i++){
		sum += (arg[i] -mittel) * (arg[i] -mittel);
	}
	return sum / (length - 1);
}

int main(int argc, char const *argv[]){
	int n;
	int check;
	while(1){
		printf("Bitte gebe die Groesse der Stichprobe ein: ");
		check = scanf("%d", &n);
		printf("\n");
		if (check != 1 || n < 0) {
			printf("falscher Input.");
		}else{
			break;
		}
	}
	double array[n];
	
	double values;
	for(int i = 0; i < n; i++){
		while(1){
			printf("Bitte sie den Wert an stelle %d ein: ", i);
			int check = scanf("%lf", &values);
			printf("\n");
			if (check != 1) {
				printf("falscher Input.");
			}else{
				break;
			}
		}
		array[i] = values;
	}
	printf("arithmetische Mittel: %lf", aMittel(array, n));
	printf(" Stichprobenvarianz: %lf", varianz(array, n));

	return 0;
}