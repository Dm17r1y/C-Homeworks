#include "hex_lib.h"

typedef struct structure {
	int a;
	char b[20];
	float c;
} structure;

int main() {
	structure s = {12, "abc", 4.5};
	print_struct_hex(&s, sizeof(s));
}
