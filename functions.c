#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filter(
	void *from,
	void *to,
	size_t size, 
	size_t count, 
	int (*filter_func)(void *element)
);

void reduce(
	void *from,
	void *to,
	size_t size,
	size_t count,
	void (*reduce_func)(void *first, void *second, void* result)
); 

int filter_int(void *element) {
	int int_element = *(int*)element;
	return int_element < 100 && int_element > -100;
}

void sum(void* first_ptr, void* second_ptr, void* result) {
	int first = *(int*)first_ptr;
	int second = *(int*)second_ptr;
	*(int*)result = first + second;
}

int main(void) {
	int arr[] = { 1, 2, 3, 66, 77, 111, 112, 13, 100000, -1111111, -1, 0 };
	int to_arr[20];
	int new_size = filter(arr, to_arr, sizeof(int), sizeof(arr)/sizeof(int), filter_int);
		puts("Filter");
	for (int i = 0; i < new_size; i++) {
		printf("%d ", to_arr[i]);
	}
	puts("");
	
	int arr_2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 100, 200 };
	int to;
	reduce(arr_2, &to, sizeof(int), 10, sum);
	puts("Reduce");
	printf("%d\n", to);
	return 0;
}

int filter(
	void *from,
	void *to,
	size_t size, 
	size_t count, 
	int (*filter_func)(void *element)
) {
	char *from_ptr = (char*)from;
	char *to_ptr = (char*)to;
	int index = 0;
	for (int i = 0; i < count; i++) {
		if (filter_func(from_ptr + size*i)) {
			memcpy(to_ptr + size*index, from_ptr + size*i, size);
			index++;
		}
	}
	return index;
}

void reduce(
	void *from,
	void *to,
	size_t size,
	size_t count,
	void (*reduce_func)(void *first, void *second, void *result)
) {
	char *from_ptr = (char*)from;
	char *to_ptr = (char*)to;
	if (size == 0) {
		return;
	}
	memcpy(to_ptr, from_ptr, size);
	void* temp = calloc(1, size);
	
	for (int i = 1; i < count; i++)	{
		reduce_func(from_ptr + size*i, to_ptr, to);
	}
	free(temp);
}

