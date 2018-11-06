#include<stdio.h>
#include<math.h>

//Auskommentiert, da float-array Bullshit produziert.
float floatsum(float *array, unsigned len){
	float erg = 0;
	for(int i = 0; i<len; i++){
		erg+= array[i];	
	}
	return erg;
}

/*float floatsum(float x1, float x2, float x3, float x4, float x5){
	return x1+x2+x3+x4+x5;
}*/

double doublesum(double *array, unsigned len){
	double erg = 0;
	for(int i =0; i<len; i++){
		erg+= array[i];	
	}
	return erg;
}

//Auskommentiert, da float-array Bullshit produziert.
float newsum(float *array, unsigned len){
	float s = 0, sold = 0, d = 0;
	for(int i = 0; i<len; i++){
		sold = s;
		s += array[i];
		d += (array[i] - (s - sold));
		s = s + d;
	}
	return s;
} 

/*float newsum(float x1, float x2, float x3, float x4, float x5){
	float s = 0, sold = 0, d = 0;
	//x1
		sold = s;
		s += x1;
		d += (x1 - (s - sold));
		s = s + d;
	//x2
		sold = s;
		s += x2;
		d += (x2 - (s - sold));
		s = s + d;
	//x3
		sold = s;
		s += x3;
		d += (x3 - (s - sold));
		s = s + d;
	//x4
		sold = s;
		s += x4;
		d += (x4 - (s - sold));
		s = s + d;
	//x5
		sold = s;
		s += x5;
		d += (x5 - (s - sold));
		s = s + d;
	return s;
}*/

double newsum_double(double *array, unsigned len){
	double s = 0, sold = 0, d = 0;
	for(int i = 0; i<len; i++){
		sold = s;
		s += array[i];
		d += (array[i] - (s - sold));
		s = s + d;
	}
	return s;
}

int main(void){
	//Laden in Floatarray liefert schwachsinn???
	float xf[4]; // = {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
	xf[0] = 10000;
	xf[1] =  -1.0e-3/9.0;
	xf[2] = 25.0e2;
	xf[3] = 1.0e-3/7.0;
	xf[4] = -12.5e3;
	
	//float x1= 10000.0, x2=-1.0e-3/9.0, x3 = 25.0e2, x4=1.0e-3/7.0, x5=-12.5e3;
	//printf("[%f, %f, %f, %f, %f]", x1, x2, x3, x4, x5);
	
	double xd[4]; //= {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
	xd[0] = 10000;
	xd[1] =  -1.0e-3/9.0;
	xd[2] = 25.0e2;
	xd[3] = 1.0e-3/7.0;
	xd[4] = -12.5e3;
	
	//Für Suche nach Fehlern
	for(int i = 0; i<5; i++){
		printf("[%f] - ", xf[i]);
		printf("[%lf]\n", xd[i]);
	}
	
	//printf("float-Summe: %f\n", floatsum(x1, x2, x3, x4, x5));
	printf("float-Summe: %f\n", floatsum(xf, 5));
	printf("double-Summe: %lf\n", doublesum(xd, 5));
	//printf("Algorithmus: %f\n", newsum(x1, x2, x3, x4, x5));
	printf("Algorithmus - float: %f\n", newsum(xf, 5));
	printf("Algorithmus - double: %lf\n", newsum_double(xd, 5));
	return 0;
}