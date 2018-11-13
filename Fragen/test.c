#include <stdio.h>

int main(int argc, char const *argv[])
{
	int number;
	scanf("%d", &number);
	
	int array[number];

	array[0] = 0;
	array[1] = 1;

	printf("%i, %i", array[0], array[1]);
	return 0;
}