#include <stdio.h>

int main(void) 
{
	double first;
	double second;
	double third;
	scanf("%lf %lf %lf", &first, &second, &third);
	if ((first*first + second*second == third*third) || 
		(first*first + third*third == second*second) ||
		(second*second + third*third == first*first))
	{
		puts("True");
	}
	else 
	{
		puts("False");
	}
}
