/* Ramesh’s basic salary is input through the keyboard. His 
dearness allowance is 40% of basic salary, and house rent 
allowance is 20% of basic salary. Write a program to calculate 
his gross salary. */

#include <stdio.h>

int main()
{
  int b;
  float d, h, g;

  printf("enter the basic salary of Ramesh:");
  scanf("%d", &b);

  /*b = basic salary
      d = dearness allowance
     h = house rent allowance*/

  d = 0.4 * b;
  h = 0.2 * b;
  
      g = b - d - h;

  printf("\n the basic salary is %d", b);
  printf("\n the dearness allownce is %f", d);
  printf("\n the house rent allowance is %f", h);
  printf("\n the gross salary is %f", g);

  return 0;
}