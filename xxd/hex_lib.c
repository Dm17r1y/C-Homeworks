#include "hex_lib.h"
#include <stdio.h>
#include <stdlib.h>

void print_struct_hex(void* struct_, size_t size) {
	char* mem = (char*)struct_;
	for (int i = 0; i < size; i++) {
		printf("%02hhx ", mem[i]);
		if (i % 8 == 7) {
			puts("");
		}
	}
	puts("");
}
