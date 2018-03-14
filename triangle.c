#include <stdio.h>
#include <math.h>

#define MAX_SYMBOLS_AFTER_COMMA 10
#define MEASUREMENT_ERROR 3

// compile with -lm

double round_number(double value, int symbols_after_comma) {
	if (symbols_after_comma > MAX_SYMBOLS_AFTER_COMMA) {
		symbols_after_comma = MAX_SYMBOLS_AFTER_COMMA;
	}
	double exponent = pow(10, symbols_after_comma);
	value *= exponent;
	value = round(value);
	return value / exponent;
}

int main(void)  {
	double first;
	double second;
	double third;
	scanf("%lf %lf %lf", &first, &second, &third);
	if ((round_number(first*first + second*second, MEASUREMENT_ERROR) == round_number(third*third, MEASUREMENT_ERROR)) || 
	    (round_number(first*first + third*third, MEASUREMENT_ERROR) == round_number(second*second, MEASUREMENT_ERROR)) ||
	    (round_number(second*second + third*third, MEASUREMENT_ERROR) == round_number(first*first, MEASUREMENT_ERROR))) {
		puts("True");
	}
	else {
		puts("False");
	}
}
