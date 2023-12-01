#include <stdio.h>

int main () {
    int num, sum = 0;
    scanf("%d", &num);
    while (num > 0) {
        sum = sum + num % 10;
        num = (num - num % 10) / 10;
    }
    printf("%d\n", sum);

    return 0;
}