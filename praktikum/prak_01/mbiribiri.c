#include <stdio.h>
#include <math.h>
#include "point.h"
#include "garis.h"

int main () {
    int b;
    scanf("%d", &b);
    GARIS serigala;
    BacaGARIS(&serigala);

    int n;
    scanf("%d", &n);
    POINT domba;
    int i, save=0;
    for (i = 0; i < n; i++) {
        BacaPOINT(&domba);
        if (JarakGARIS(serigala, domba) < b) {
            save++;
        }
    }
    printf("%d\n", save);
}