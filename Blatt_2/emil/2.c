#include <stdio.h>

unsigned long long long_fib_rec(long n){
	if(n < 2) return n;
	return long_fib_rec(n - 1) + long_fib_rec(n - 2);
}

void printFirst50EvenFib(){
	int counter = 1;
	unsigned long long a = 0;
	unsigned long long b = 1;
	unsigned long long c;
	printf("%i. gerade Fib: %llu\n", counter, a);
	counter++;
	while(counter <= 50){
		c = a + b;
		a = b;
		b = c;
		if(b % 2 == 0){
			printf("%i. gerade Fib: %llu\n", counter, b);
			counter++;
		}
	}
}

int main(int argc, char const *argv[]){
	int number;
	puts("Bitte gib eine nicht negative, ganze Zahl ein: ");
	int check = scanf("%i", &number);
	//wenn die Eingabe das falsche Format hat oder die Eingabe negativ ist
	if (check != 1 || number < 0){
		puts("Fehlerhafte Eingabe!");
		return 1;
	}
	
	printf("%i Fib: %llu\n", number, long_fib_rec(number));
	puts("\n Die ersten 50 geraden Fibonacci-Zahlen:");
	printFirst50EvenFib();
	return 0;
}
