#include <stdio.h>
#include <math.h>
int special_number(int number)
{
    int n = number;
    int digits[10];
    int a;
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        digits[i] = number % 10;
        number = number / 10;
        if (pow(10, i) <= n)
        {
            a = i;
        }
    }
    for (int i = 0; i <= a; i++)
    {
        temp = temp + pow(digits[i], a - i + 1);
    }
    if (temp == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;

    printf("Name: Deep Aryan Saini , ROLL NO : 2K20/A17/49");
    printf("\nenter the number : ");
    scanf("%d", &n);
    if (special_number(n) == 0)
    {
        printf("the number is not a special number");
    }
    else
    {
        printf("the number is a special number");
    }
    return 0;
}