#include <stdio.h>

int succ(int x) {
    return ++x;
}

int pre(int x) {
    return --x;
}

int add(int x, int y) {
    return (y>0?add(pre(x), succ(y)):x);
}

int sub(int x, int y) {
    return 0;
}

int mult(int x, int y) {
    return 0;
}


int main() {
    int x = 0, y = 0;
    printf("Enter number 1:\t");
    scanf("%d", &x);
    printf("Enter number 2:\t");
    scanf("%d", &y);
    while (y < 0) {
        printf("Second gotta be positive you dwub:\t");
        scanf("%d", &y);
    }
    printf("%d %d", x, y); //just fucking dies
    printf("add(%i %i): %i", x, y, add(x,y));
    printf("sub(%i, %i): %i", x, y, sub(x,y));
    printf("mult(%i, %i): %i", x, y, mult(x,y));

    return 1;
}