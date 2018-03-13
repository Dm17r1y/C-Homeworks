#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	int digits = 0;
	int letters = 0;
	char c;
	while ((c = getc(stdin)) != EOF)
	{
		if (isdigit(c))
		{
			digits++;
		}
		else if (isalpha(c))
		{
			letters++;
		}
	}
	printf("Digits: %d \n", digits);
	printf("Latin symbols: %d \n", letters);
}
