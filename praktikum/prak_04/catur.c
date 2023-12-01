#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

int main() {
    Matrix catur;
    readMatrix(&catur, 8, 8);

    int count_putih = 0;
    int count_hitam = 0;
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (ELMT(catur, i, j) == 1) {
                if ((i+j)%2 == 0) {
                    count_hitam++;
                } else {
                    count_putih++;
                }
            }
        }
    }
    printf("%d %d\n", count_hitam, count_putih);
}