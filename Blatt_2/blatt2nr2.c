#include<stdio.h>

long fib_rec(long n){
	if(n == 0){
		return 0;
	} else if (n == 1){
		return 1;
	} else {
		return fib_rec(n-1) + fib_rec(n-2);
	}
}

//Anmerkung: Bereits fast nicht zu schaffen für n = 15
long long fib_even_sum(long n){
	long long erg = 0;
	int hits = 0; //zum zaehlen bis n gerade fibonacci-zahlen
	int index = 1;
	while(hits < n){
		long tmp = fib_rec(index);
		if(tmp%2 == 0){
			erg += tmp;
			//Zur Kontrolle der zu summierenden Zahlen
			//printf(" [%ld] ", tmp);
			hits++;
		}
		index++;
	}
	return erg;
}

int main(void){
	long n;
	printf("Bitte ganze Zahl eingeben (sinnvoll nur fuer natuerliche Zahl...): ");
	scanf("%ld", &n);
	
	printf("f(%ld) = %ld", n, fib_rec(n));
	printf("\nSumme der ersten %ld geraden Fibonacci-Zahlen ist: %lld", n , fib_even_sum(n));
	
	return 0;
}
