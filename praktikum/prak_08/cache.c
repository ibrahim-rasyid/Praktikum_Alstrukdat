#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"

int main() {
    int size, op, i, x, del, idx, hit=0;
    float ratio;
    List cache;
    CreateList(&cache);

    scanf("%d", &size);
    scanf("%d", &op);

    if (size != 0) {
        for (i=0; i<op; i++) {
            scanf("%d", &x);
            if (isEmpty(cache)) {
                insertFirst(&cache, x);
                printf("miss ");
            } else {
                idx = indexOf(cache, x);
                if (idx != IDX_UNDEF) {
                    deleteAt(&cache, idx, &del);
                    insertFirst(&cache, x);
                    printf("hit ");
                    hit++;
                } else {
                    if (length(cache) == size) {
                        deleteLast(&cache, &del);
                    }
                    insertFirst(&cache, x);
                    printf("miss ");
                }
            }
            displayList(cache);
            printf("\n");
        }
    } else {
        for (i=0; i<op; i++) {
            scanf("%d", &x);
            printf("miss []\n");
        }
    }
    if (op == 0) {
        ratio = 0;
    } else {
        ratio = (float) hit/op;
    }
    printf("hit ratio: %.2f\n", ratio);
}