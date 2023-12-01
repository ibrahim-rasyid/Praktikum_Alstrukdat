#include <stdio.h>

int main () {
    int a, b, n;
    scanf("%d %d", &a, &b);
    for (a; a <= b; a++) {
        if (a % 11 == 0) {
            n++;
        }
    }
    printf("%d\n", n);

    return 0;
}