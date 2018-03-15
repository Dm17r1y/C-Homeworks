#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 0.001

bool is_triangle(int, int, int);
bool is_equial(double, double, double);

int main(void)  {
	double first;
	double second;
	double third;
	scanf("%lf %lf %lf", &first, &second, &third);
	if (!is_triangle(first, second, third)) {
		puts("Not a triangle");
		exit(1);
	}
	if (is_equial(first*first + second*second, third*third, EPSILON)) {
		puts("True");
	}
	else {
		puts("False");
	}
}

bool is_triangle(int a, int b, int c) {
	return a + b > c && a + c > b && b + c > a;
}

bool is_equial(double first, double second, double epsilon) {
	return fabs(first - second) < epsilon;
}
