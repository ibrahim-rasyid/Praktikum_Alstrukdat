#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main() {
    Stack S;
    int x, val, fibo;
    
    CreateEmpty(&S);

    scanf("%d", &x);
    Push(&S, x);
    while (!IsEmpty(S)) {
        Pop(&S, &val);
        printf("fibonacci(%d)\n", val);
        if (val == 0) {
            fibo += 0;
        } else if (val == 1) {
            fibo++;
        } else {
            Push(&S, val-1);
            Push(&S, val);
        }
    }
    printf("%d\n", fibo);
}