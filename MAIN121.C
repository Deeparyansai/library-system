#include <stdio.h>
float *arraysum(int *ptr)
{
    static float sum = 0.0;
    for (int i = 0; i < 6; i++)
    {
        sum += *(ptr + i);
    }
    return (&sum);
}
int main()
{
    int array[6] = {1, 3, 3, 4, 35, 6};
    float *total;

    total = arraysum(array);
    float average = (*total) / 6;
    printf("Average of the given array is: %f\n", average);
    return 0;
}
