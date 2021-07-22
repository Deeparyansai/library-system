 #include <stdio.h>
// Typecasting Syntax
// (type) value;
int main()
{

	int a = 3;
	float n= (float)54/5;
	printf("The Value of a is %f\n", a );
	return 0;

}



#include<stdio.h> 
int main() 
{ 
	short a=10; //initializing variable of short data type 
	int b; //declaring int variable 'b'. 
	b=a; //Implicit type casting 
	printf("%d\n",a); 
	printf("%d\n",b); 
} 

#include<stdio.h> 
int main() 
{ 
	int a; 
	float b; 
	char c; 
	printf("Enter the value of a\n"); 
	scanf("%d",&a); 
	printf("A is %d\n", a); 
	printf("Enter the value of b\n"); 
	scanf("%f",&b ); 
	printf("B is %d\n", (int) b); 
	printf("Type any character : \n"); 
	scanf(" %c",&c ); 
	printf("Character is %d",(int) c); 
	return 0; 
}