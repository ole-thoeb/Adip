#include <stdio.h>

int main(int argc, char const *argv[])
{
	for(int i = 1; i <= 10 ; i++){
		
		for(int j = 1; j <= 10; j++)
		{
			printf("%i x %i = %i\n", j, i, i*j);
		}
		puts("");
	}
	return 0;
}
