#include <stdio.h>

void addsub(int *a, int *b)
{
    *a = *a + *b;
    *b = (*a-*b) - *b;
}

int main()
{
    int a = 4, b = 3;

    printf("a+b = %d\n", a + b);
    printf("a-b = %d\n", a - b);

    addsub(&a, &b);

    printf("the value of a is %d\n", a);
    printf("the value of b is %d\n", b);
    return 0;
}
