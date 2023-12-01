#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main() {
    ListStatik l1, l2;
    int num1=0, num2=0, i, diff;
    boolean simpan=false;

    readList(&l1);
    readList(&l2);

    if (listLength(l1) >= listLength(l2)) {
        diff = listLength(l1)-listLength(l2);
        for (i=0; i<diff; i++) {
            insertFirst(&l2, 0);
        }
    } else {
        diff = listLength(l2)-listLength(l1);
        for (i=0; i<diff; i++) {
            insertFirst(&l1, 0);
        }
    }
    for (i=listLength(l2)-1; i>=0; i--) {
        ELMT(l1, i) += ELMT(l2, i);
        if (simpan) {
            ELMT(l1, i)++;
        }
        if (ELMT(l1, i) >= 10) {
            ELMT(l1, i) -= 10;
            simpan = true;
        } else {
            simpan = false;
        }
    }
    if (simpan) {
        insertFirst(&l1, 1);
    }
    printList(l1); printf("\n");
}