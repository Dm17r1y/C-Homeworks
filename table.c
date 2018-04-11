#include <stdio.h>

int main(void) {
    int squares[9][10];
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            *(*(squares + i - 1) + j) = (i*10 + j) * (i*10 + j);
        }
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%5d", *(*(squares + i - 1) + j));
        }
        puts("");
    }

    return 0;
}
