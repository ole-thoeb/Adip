#include <stdlib.h>
#include <stdio.h>

void printArg(int *arg, size_t size){
	for(int i = 0; i < size; i++){
		printf("%i,", arg[i]);
	}
	putchar('\n');
}

int main(int argc, char const *argv[])
{	
	int *arg = malloc(4 * sizeof(int));
	if(!arg){
		puts("fehler mall");
		return 1;
	}
	int size = 4;
	
	for(size_t i = 0; i < size; i++){
		arg[i] = i;
	}
	puts("Hallo");

	for(int i = 0; i < 50; i++){
		arg = realloc(arg, size * sizeof(int));
		if(!arg){
			printf("fehler rea in %i\n", i);
			//puts("fehler rea");
			return 1;
		}
		size++;
		arg[size - 1] = i;
	}

	printf("Size %i\n", size);
	/*
	for(size_t i = 4; i < size; i++)
	{
		arg[i] = i;
	}*/
	
	printArg(arg, size);
	
	return 0;
}