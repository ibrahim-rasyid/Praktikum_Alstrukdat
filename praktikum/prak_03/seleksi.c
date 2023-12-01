#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listdin.h"
#include "boolean.h"

int main () {
    int c;
    scanf("%d", &c);
    ListDin A;
    CreateListDin(&A, c);
    int qu, i;
    scanf("%d", &qu);

    for (i=0; i<qu; i++) {
        int tipe, x;
        scanf("%d", &tipe);
        if (tipe == 1) {
            scanf("%d", &x);
            insertLast(&A, x);
            sort(&A, false);
            while (ELMT(A, listLength(A)-1) < x) {
                deleteLast(&A, ELMT(A, listLength(A)-1));
            }
        } else {
            printf("%d\n", listLength(A));
            printList(A); printf("\n");
        }
    }

    return 0;
}