#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

boolean inMatrix(Matrix m1, Matrix m2) {
    // ukuran m1 > ukuran m2
    int a = ROW_EFF(m1);
    int b = COL_EFF(m1);
    int m = ROW_EFF(m2);
    int n = COL_EFF(m2);

    boolean in = false;
    int i, j, x, y;
    for (i=0; i<=(a-m); i++) {
        for (j=0; j<=(b-n); j++) {
            Matrix sub_m1;
            createMatrix(m, n, &sub_m1);
            for (x=0; x<m; x++) {
                for (y=0; y<n; y++) {
                    ELMT(sub_m1, x, y) = ELMT(m1, i+x, j+y);
                }
            }
            if (isMatrixEqual(sub_m1, m2) == true) {
                in = true;
            }
        }
    }
    return in;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Matrix puzzle;
    readMatrix(&puzzle, n, m);

    int k;
    scanf("%d", &k);

    int i;
    boolean solvable = true;
    
    for (i=0; i<k; i++) {
        Matrix piece;
        int a, b;
        scanf("%d %d", &a, &b);
        readMatrix(&piece, a, b);
        if (inMatrix(puzzle, piece) == false) {
            solvable = false;
        }
    }

    if (solvable == true) {
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}