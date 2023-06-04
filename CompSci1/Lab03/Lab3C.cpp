/*Author: Nicholas Bright(nicholasbright@my.unt.edu)
9/10/20
shrestha
description: inputing 2 integers and 2 double variables using printf and scanf and
using them in equations to change the value for  a,b,c,d  using printf
*/
#include<iostream>
using namespace std;

int main()
{
	int a;
	int b;
	double c;
	double d;

	printf( "Enter two integer values: \n");
	scanf("%i %i", &a, &b);

	printf("Enter two double values: \n");
	scanf( "%lf %lf", &c,&d);

	printf("You just enterded the inegers values:%i,%i, and the double values: %lf, %.3f \n",a,b,c,d);\

	a=a+b;
	d=d/a;
	c=c*5;
	b=b%a;
	c=a-c;

	printf("The final values are:\n a=%i \n b=%i \n c=%lf \n d=%.3f \n", a,b,c,d);




	return 0;
}
