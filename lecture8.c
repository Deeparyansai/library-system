/*do {
   statements );
} while( test condition )*/

#include <stdio.h>

int main()
{
    int num, index = 0;
    printf("Enter a number\n");
    scanf("%d", &num);
    do
    {
        printf("%d\n", index + 1);
        index = index + 1;
    } while (index < num);

    return 0;
}

#include <stdio.h>
int main()
{
    int n, sum = 0;
    do
    {  
printf("Enter a number: ");
scanf("%i", &n);
        sum += n;
    }
    while(n != 0);
    printf("Sum is = %d",sum);

    return 0;
}