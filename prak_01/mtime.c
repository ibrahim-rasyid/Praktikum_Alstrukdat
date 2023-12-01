#include <stdio.h>
#include "time.h"

int main () {
    int n, i;
    scanf("%d", &n);
    TIME mulaiAwal, mulai, tTemp;
    TIME selesaiAkhir, selesai;
    CreateTime(&mulaiAwal, 23, 59, 59);
    CreateTime(&selesaiAkhir, 0, 0, 0);
    long dur;
    for (i=1; i<=n; i++) {
        printf("[%d]\n", i);

        BacaTIME(&mulai);
        // int HH, MM, SS;
        // scanf("%d %d %d", &HH, &MM, &SS);
        // while (!IsTIMEValid(HH, MM, SS)) {
        //     printf("Jam tidak valid\n");
        //     scanf("%d %d %d", &HH, &MM, &SS);
        // }
        // CreateTime(&mulai, HH, MM, SS);

        BacaTIME(&selesai);
        // scanf("%d %d %d", &HH, &MM, &SS);
        // while (!IsTIMEValid(HH, MM, SS)) {
        //     printf("Jam tidak valid\n");
        //     scanf("%d %d %d", &HH, &MM, &SS);
        // }
        // CreateTime(&selesai, HH, MM, SS);

        if (TLT(selesai, mulai)) {
            tTemp = mulai;
            mulai = selesai;
            selesai = tTemp;
        }

        dur = Durasi(mulai, selesai);
        printf("%d\n", dur);

        if (TLT(mulai, mulaiAwal)) {
            mulaiAwal = mulai;
        }
        if (TGT(selesai, selesaiAkhir)) {
            selesaiAkhir = selesai;
        }
    }
    TulisTIME(mulaiAwal);
    TulisTIME(selesaiAkhir);
}