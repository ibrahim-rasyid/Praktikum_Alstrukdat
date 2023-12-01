#include <stdio.h>

int main () {
    int n, i=0;
    scanf("%d", &n);
    int tb = 0, tb2 = 0, x;
    for (i; i < n; i++) {
        scanf("%d", &x);
        if (x > tb) {
            tb = x;
        } else if (x > tb2) {
            tb2 = x;
        }
    }

    printf("%d\n", tb2);

    return 0;
}