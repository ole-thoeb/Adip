#include <stdio.h>
#include <stdlib.h>

typedef struct TreeArray{
	char *el;
	int size;
}TreeArray;

struct d2TreeArrayImpl{
	TreeArray **el;
	int size;
};

typedef struct d2TreeArrayImpl d2TreeArray;

int power(int x, int n){
    int k = 1;
    if(n == 0){
        return 1;
    }
    while(n > 1){
        if((n % 2) != 0){
            n--;
            k *= x;
        }else{
            n /= 2;
            x *= x;
        }
    }
    return x * k;
}

int main(int argc, char const *argv[]){
	/*int depth = 10;

	d2TreeArray *arg = malloc(sizeof(struct d2TreeArrayImpl));
	arg->el = malloc(sizeof(struct TreeArray) * depth);
	arg->size = depth;
	puts("welp");
	for(size_t i = 0; i < depth; i++){
		puts("malloc");
		int amount = power(2, i);
		printf("a %i\n", amount);
		char *temp = malloc(sizeof(char) * amount);
		printf("%i, p: %i\n", i, temp);
		arg->el[i]->size = amount;
		arg->el[i]->el = temp;
	}*/
	int depth = 10;

	TreeArray **el = malloc(sizeof(TreeArray*) * depth);
	puts("welp");
	for(size_t i = 0; i < depth; i++){
		puts("malloc");
		int amount = power(2, i);
		printf("a %i\n", amount);
		char *temp = malloc(sizeof(char) * amount);
		printf("%i, p: %i\n", i, temp);
		el[i] = malloc(sizeof(TreeArray));
		el[i]->size = amount;
		el[i]->el = temp;
	}

	return 0;
}
