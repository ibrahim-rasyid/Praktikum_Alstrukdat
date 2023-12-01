#include <stdio.h>
#include "list_circular.h"

int main () {
    int N, a, i, j, m, val;
    List l;
    Address buku;

    scanf("%d", &N);
    CreateList(&l);
    for (i=1; i<N+1; i++) {
        val = i;
        insertLast(&l, val);
    }

    buku = FIRST(l);
    m = N;
    for (i=0; i<N-1; i++) {
        scanf("%d", &a);
        if (a > 0) {
            if (i == 0) {
                for (j=0; j<a; j++) {
                    buku = NEXT(buku);
                }
            } else {
                for (j=0; j<a-1; j++) {
                    buku = NEXT(buku);
                }
            }
        } else {
            if (i == 0) {
                for (j=0; j<m+a; j++) {
                    buku = NEXT(buku);
                }
            } else {
                for (j=0; j<m+a; j++) {
                    buku = NEXT(buku);
                }
            }
        }
        FIRST(l) = buku;
        buku = NEXT(buku);
        deleteFirst(&l, &val);
        m--;
    }
    printf("%d\n", INFO(buku));
}