#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main() {
    ListStatik l1, l2;
    readList(&l1);
    readList(&l2);
    ListStatik l3;
    CreateListStatik(&l3);
    int i;
    insertFirst(&l3, ELMT(l1, 0));
    for (i=1; i<listLength(l1); i++) {
        // printf("%d", i);
        insertLast(&l3, ELMT(l1, i));
    }
    for (i=0; i<listLength(l2); i++) {
        // printf("%d", i);
        insertLast(&l3, ELMT(l2, i));
    }
    sortList(&l3, true);
    printList(l3);
    printf("\n");
}