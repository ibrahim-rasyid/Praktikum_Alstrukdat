#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listdin.h"
#include "boolean.h"

int main () {
    ListDin A;
    CreateListDin(&A, 0);
    int query, i, tipe;
    scanf("%d", &query);
    for (i=0; i<query; i++) {
        scanf("%d", &tipe);
        if (tipe == 1) {
            int x;
            scanf("%d", &x);
            if (CAPACITY(A) == 0) {
                expandList(&A, 1);
            } else if (isFull(A)) {
                expandList(&A, CAPACITY(A));
            }
            insertLast(&A, x);
        } else if (tipe == 2) {
            int val;
            deleteLast(&A, &val);
            int half = round(CAPACITY(A)/2);
            if (NEFF(A) < half) {
                shrinkList(&A, CAPACITY(A)-round(CAPACITY(A)/2));
            }
        } else {
            printf("%d\n", CAPACITY(A));
            printList(A); printf("\n");
        }
    }
    return 0;
}