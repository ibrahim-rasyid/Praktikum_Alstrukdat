#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main () {
    ListStatik l;
    readList(&l);

    int sum = 0, i, x;
    int max, min, med;
    int idx_x;
    boolean found = false;
    scanf("%d", &x);
    for (i=0; i<listLength(l); i++) {
        sum += ELMT(l, i);
    }
    sortList(&l, true);
    printList(l); printf("\n");
    idx_x = indexOf(l, x);
    extremeValues(l, &max, &min);
    int idx_med;
    if (listLength(l)%2 == 0) {
        idx_med = (int) listLength(l)/2 - 1;
    } else {
        idx_med = (int) (listLength(l)+1)/2;
    }
    float avg = (float) sum/listLength(l);
    printf("Average: %.2f\n", avg);
    if (idx_x == -1) {
        printf("%d tidak ada\n", x);
    } else {
        printf("%d\n", idx_x);
    }
    if (x == max) {
        printf("X maksimum\n");
    }
    if (x == min) {
        printf("X minimum\n");
    }
    if (ELMT(l, idx_med) == x) {
        printf("X median\n");
    }
}