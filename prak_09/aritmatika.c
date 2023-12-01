#include <stdio.h>
#include "list_circular.h"

int main() {
    int N, a, b, val, i, dif, preval;
    boolean arith;
    List l;

    scanf("%d", &N);
    CreateList(&l);
    for (i=0; i<N; i++) {
        scanf("%d", &val);
        insertLast(&l, val);
    }

    Address p = FIRST(l);
    arith = true;
    while (NEXT(p) != FIRST(l) && arith) {
        val = INFO(p);
        if (p == FIRST(l)) {
            b = val;
        } else if (p == NEXT(FIRST(l))) {
            a = val-b;
        } else {
            dif = val-preval;
            if (dif != a) {
                arith = false;
            }
        }
        preval = val;
        p = NEXT(p);
    }
    

    if (!arith) {
        a = 0;
        b = 0;
    }
    printf("%d %d\n", a, b);
}