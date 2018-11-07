#include <stdio.h>

float f(){
	float x1 = 10000.0f;
	float x2 = -0.001f / 9.0f;
	float x3 = 2500.0f;
	float x4 = 0.001f / 7.0f;
	float x5 = -12500.0;

	return x1 + x2 + x3 + x4 + x5;
}

double d(){
	double x1 = (double)10000.0;
	double x2 = (double)-0.001 / (double)9.0;
	double x3 = (double)2500.0;
	double x4 = (double)0.001 / (double)7.0;
	double x5 = (double)-12500.0;

	return x1 + x2 + x3 + x4 + x5;
}

float sf(){
	float arg[5]= {10000.0f, (-0.001f / 9.0f), 2500.0f, (0.001f / 7.0f), -12500.0f};

	float s = 0.0;
	float d = 0.0;
	float SAlt;
	
	for(int i = 0; i < 5; i++){
		SAlt = s;
		s += arg[i];
		d += (arg[i] - (s - SAlt));
		s += d;
	}
	return s;
}

double sd(){
	double arg[5]= {10000.0, (-0.001 / 9.0), 2500.0, (0.001 / 7.0), -12500.0};

	double s = 0.0;
	double d = 0.0;
	double SAlt;
	
	for(int i = 0; i < 5; i++){
		SAlt = s;
		s += arg[i];
		d += (arg[i] - (s - SAlt));
		s += d;
	}
	return s;
}

int main(int argc, char const *argv[])
{
	printf("float: %f\n", f());
	printf("double: %lf\n", d());
	printf("summF: %f\n", sf());
	printf("summD: %lf\n", sd());
	return 0;
}


/*
a) 2 / 63000
b) 0.000032
c) 0.000032
d) 0.000032
e) kein Plan
f) 0.000032
*/