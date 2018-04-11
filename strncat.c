#include <stdio.h>
#include <stdlib.h>

char* strncat(char* dest, char* src, size_t size) {
	size_t end_str = 0;
	while (*(dest + end_str) != 0) {
		end_str++;
	}
	size_t index = 0;
	while (*(src + index) != 0 && index < size) {
		*(dest + end_str + index) = *(src + index);
		index++;
	}
	return dest;
}

int main(void) {
	char str1[10] = "abc";
	char str2[10] = "def";
	puts(strncat(str1, str2, 3));
	return 0;
}
