/*for ( initialization; test condition; increment ) {
   for ( initialization; test condition; increment ) {
    // set of statements
   }   
   // set of statements
}*/

#include <stdio.h>

int main()
{
    printf("Hello World\n");
    int i, j=0;
    for(i=0 ;  ; )
    {
       printf("%d %d\n", i, j);
       i++;j++;
    }
    
    return 0;
}