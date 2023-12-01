#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    int i, j;
    for (i=0; i<ROW_EFF(*m); i++) {
        for (j=0; j<COL_EFF(*m); j++) {
            ELMT(*m, i, j) = 0;
        }
    }
}

boolean isMatrixIdxValid(int i, int j) {
    return (0<=i && i<=ROW_CAP && 0<=j && j<=COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return (ROW_EFF(m)-1);
}

IdxType getLastIdxCol(Matrix m) {
    return (COL_EFF(m)-1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (0<=i && i<=ROW_EFF(m)-1 && 0<=j && j<=COL_EFF(m)-1);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int nRows = ROW_EFF(mIn);
    int nCols = COL_EFF(mIn);
    createMatrix(nRows, nCols, mOut);
    int i, j;
    for (i=0; i<ROW_EFF(*mOut); i++) {
        for (j=0; j<COL_EFF(*mOut); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    int i,j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;
    for (i=0; i<ROW_EFF(m); i++) {
        for (j=0; j<COL_EFF(m); j++) {
            if (j==0) {
                printf("%d", ELMT(m, i, j));
            } else {
                printf(" %d", ELMT(m, i, j));
            }
        }
        printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i=0; i<ROW_EFF(m3); i++) {
        for (j=0; j<COL_EFF(m3); j++) {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i=0; i<ROW_EFF(m3); i++) {
        for (j=0; j<COL_EFF(m3); j++) {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    int i, j, k;
    for (i=0; i<ROW_EFF(m1); i++) {
        for (j=0; j<COL_EFF(m2); j++) {
            for (k=0; k<ROW_EFF(m2); k++) {
                ELMT(m3, i, j) += ELMT(m1, i, k) + ELMT(m2, k, j);
            }
        }
    }
    return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
    Matrix m3;
    m3 = multiplyMatrix(m1, m2);
    int i, j;
    for (i=0; i<ROW_EFF(m3); i++) {
        for (j=0; j<COL_EFF(m3); j++) {
            ELMT(m3, i, j) = ELMT(m3, i, j)%mod;
        }
    }
}

Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix m2;
    copyMatrix(m, &m2);
    int i, j;
    for (i=0; i<ROW_EFF(m2); i++) {
        for (j=0; j<COL_EFF(m2); j++) {
            ELMT(m2, i, j) *= x;
        }
    }
    return m2;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    int i, j;
    for (i=0; i<ROW_EFF(*m); i++) {
        for (j=0; j<COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    boolean eq = true;
    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))) {
        eq = false;
    } else {
        int i, j;
        for (i=0; i<ROW_EFF(m1); i++) {
            for (j=0; j<COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    eq = false;
                }
            }
        }
    }
    return eq;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
}

int countElmt(Matrix m) {
    return ROW_EFF(m)*COL_EFF(m);
}

boolean isSquare(Matrix m) {
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
    boolean sym = true;
    if (isSquare(m)) {
        sym = false;
    } else {
        int i, j;
        for (i=0; i<ROW_EFF(m); i++) {
            for (j=0; j<COL_EFF(m); j++) {
                if (ELMT(m, i, j) != ELMT(m, j, i)) {
                    sym = false;
                }
            }
        }
    }
    return sym;
}

boolean isIdentity(Matrix m) {
    boolean idt = true;
    if (isSquare(m)) {
        idt = false;
    } else {
        int i, j;
        for (i=0; i<ROW_EFF(m); i++) {
            for (j=0; j<COL_EFF(m); j++) {
                if ((i == j) && (ELMT(m, i, j) != 1)) {
                    idt = false;
                } else if ((i != j) && (ELMT(m, i, j) != 0)) {
                    idt = false;
                }
            }
        }
    }
    return idt;
}

boolean isSparse(Matrix m) {
    boolean sparse = true;
    int count = 0;
    int i, j;
    for (i=0; i<ROW_EFF(m); i++) {
        for (j=0; j<COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                count++;
            }
        }
    }
    if (count/countElmt(m)>0.05) {
        sparse = false;
    }
    return sparse;
}

Matrix negation(Matrix m) {
    Matrix mneg = multiplyByConst(m, -1);
    return mneg;
}

void pNegation(Matrix *m) {
    pMultiplyByConst(m, -1);
}

Matrix kofaktor(Matrix m, int r, int c) {
    Matrix sub_m;
    createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &sub_m);
    int i, j, el;
    for (i=0; i<ROW_EFF(m); i++) {
        for (j=0; j<COL_EFF(m); j++) {
            el = ELMT(m, i, j);
            if (i == r) {
                
            }
        }
    }
    return sub_m;
}

float determinant(Matrix m) {
    if (ROW_EFF(m) == 1) {
        return (float) ELMT(m, 0, 0);
    } else {
        float det = 0;
        int i, j;
        for (i=0; i<ROW_EFF(m); i++) {
            Matrix sub_m;
            createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &sub_m);

        }
    }
}

Matrix transpose(Matrix m) {
    Matrix mtrans;
    createMatrix(COL_EFF(m), ROW_EFF(m), &mtrans);
    int i, j;
    for (i=0; i<ROW_EFF(m); i++) {
        for (j=0; j<COL_EFF(m); j++) {
            ELMT(mtrans, i, j) = ELMT(m, j, i);
        }
    }
    return mtrans;
}

void pTranspose(Matrix *m) {
    Matrix mtemp;
    mtemp = transpose(*m);
    copyMatrix(mtemp, m);
}