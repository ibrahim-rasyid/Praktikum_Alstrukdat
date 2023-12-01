#include <stdio.h>
#include "boolean.h"
#include "stack.h"

void SortirKeranjang (Stack * S1, Stack * S2) {
    /* Menyortir keranjang S1 menggunakan bantuan S2 */
    /* I.S. S1 tidak terurut dan S2 kosong */
    /* F.S. S1 kosong dan S2 terurut */
    /* Contoh: */
    /* TOP */
    /* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
    /* TOP */
    /* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
    int val1, val2;
    while (!IsEmpty(*S1)) {
        Pop(S1, &val1);
        if (IsEmpty(*S1)) {
            Push(S2, val1);
            break;
        }
        Pop(S1, val2);
        if (val1 < val2) {
            Push(S2, val1);
            Push(S1, val2);
        } else {
            Push(S2, val2);
            Push(S1, val1);
        }
    }
}

