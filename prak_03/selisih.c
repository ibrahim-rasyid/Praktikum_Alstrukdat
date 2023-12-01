#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listdin.h"
#include "boolean.h"

int main() {
    ListDin l;
    int n;
    scanf("%d", &n);
    while (n<0) {
        scanf("%d", &n);
    }
    CreateListDin(&l, n);
    NEFF(l) = n;
    int i = 0, el;
    for (i; i<n; i++) {
        scanf("%d", &el);
        ELMT(l, i) = el;
    }
    sort(&l, true);
    int selisih;
    if (NEFF(l) > 1) {
        selisih = ELMT(l, getLastIdx(l)) - ELMT(l, getFirstIdx(l)) + 1;
    } else {
        selisih = 0;
    }
    printf("%d\n", selisih);

    return 0;
}