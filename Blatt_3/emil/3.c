#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *numbers[9] = {"ein", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun"};
	char *tens[5] = {"zwanzig", "dreizig", "vierzig", "fuenfzig", "sechzig"};
	char *and = "-und-";

	int n;
	printf("Gib ein Zahl zwischen 20 und 69 ein: ");
	int check = scanf("%d", &n);
	printf("\n");
	
	if (check != 1 || n < 20 || n > 69) {
		printf("fehlerhafte Eingabe\n");
		return 1;
	}

	int einer = n % 10;
	int zehner = (n - einer) / 10;

	if(einer != 0){
		printf("%s", numbers[einer - 1]);
		printf("%s", and);
	}
	printf("%s", tens[zehner - 2]);
	return 0;
}
