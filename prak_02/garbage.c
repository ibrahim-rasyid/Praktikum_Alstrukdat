#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main() {
    int t1=0, t2=0, t3=0, tTot=0, i, j, idx_max;
    ListStatik lRumah, lJalan;

    readList(&lRumah);
    readList(&lJalan);

    if (indexOf(lRumah, 1) != -1) {
        for (i=0; i<listLength(lRumah); i++) {
            if (ELMT(lRumah, i) == 1) {
                idx_max = i;
            }
        }
        for (j=0; j<idx_max; j++) {
            t1 += ELMT(lJalan, j);
        }
        t1 *= 2;
    }
    if (indexOf(lRumah, 2) != -1) {
        for (i=0; i<listLength(lRumah); i++) {
            if (ELMT(lRumah, i) == 2) {
                idx_max = i;
            }
        }
        for (j=0; j<idx_max; j++) {
            t2 += ELMT(lJalan, j);
        }
        t2 *= 2;
    }
    if (indexOf(lRumah, 3) != -1) {
        for (i=0; i<listLength(lRumah); i++) {
            if (ELMT(lRumah, i) == 3) {
                idx_max = i;
            }
        }
        for (j=0; j<idx_max; j++) {
            t3 += ELMT(lJalan, j);
        }
        t3 *= 2;
    }
    for (i=0; i<listLength(lRumah); i++) {
        if (ELMT(lRumah, i) != 0) {
            tTot++;
        }
    }
    tTot += t1+t2+t3;
    printf("%d\n", tTot);
}