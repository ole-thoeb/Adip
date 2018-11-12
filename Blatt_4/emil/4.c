#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	
	for(int c = 3; c < 200; c++)
	{
		
		for(int b = 1; b < c; b++)
		{
			
			for(int a = 1; a < b; a++)
			{
				
				if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
					printf("%i, %i, %i ist ein Pythagoras-Triplet\n", a, b, c);
				}
				
			}
			
		}
		
	}
	
	return 0;
}
