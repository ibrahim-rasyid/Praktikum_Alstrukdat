#include <stdio.h>
#include "time.c"

int main () {
    TIME *T1;
    BacaTIME(T1);
    TulisTIME(*T1);

    long d1 = TIMEToDetik(*T1);
    printf("%ld\n", d1);
    
    /*TIME *T2;
    BacaTIME(T2);
    TulisTIME(*T2);

    long d2 = TIMEToDetik(*T2);
    printf("%ld\n", d2);*/

    TulisTIME(NextDetik(*T1));

    return 0;
}