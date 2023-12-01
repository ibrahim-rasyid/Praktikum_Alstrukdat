#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "time.h"

boolean IsTIMEValid (int H, int M, int S) {
    return ((0 <= H <= 23) && (0 <= M <= 59) && (0 <= S <= 59));
}

void CreateTime (TIME * T, int HH, int MM, int SS) {
    if (IsTIMEValid(HH, MM, SS) == true) {
        Hour(*T) = HH;
        Minute(*T) = MM;
        Second(*T) = SS;
    }
}

void BacaTIME (TIME * T) {
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (!IsTIMEValid(HH, MM, SS)) {
        scanf("%d %d %d", HH, MM, SS);
    }
    CreateTime(T, HH, MM, SS);
}

void TulisTIME (TIME T) {
    int HH, MM, SS;
    HH = Hour(T);
    MM = Minute(T);
    SS = Second(T);
    printf("%d:%d:%d\n", HH, MM, SS);
}

long TIMEToDetik (TIME T) {
    return (Hour(T)*3600 + Minute(T)*60 + Second(T));
}

TIME DetikToTIME (long N) {
    int N1 = N%86400;
    int HH = N1/3600;
    N1 = N1%3600;
    int MM = N1/60;
    N1 = N1%60;
    int SS = N1;
    TIME T;
    CreateTime(&T, HH, MM, SS);
    return T;
}

boolean TEQ (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}

boolean TLT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik (TIME T) {
    return (DetikToTIME(TIMEToDetik(T)+1));
}

TIME NextNDetik (TIME T, int N) {
    long N2 = N;
    return (DetikToTIME(TIMEToDetik(T)+N2));
}

TIME PrevDetik (TIME T) {
    return (DetikToTIME(TIMEToDetik(T)-1));
}

TIME PrevNDetik (TIME T, int N) {
    long N2 = N;
    return (DetikToTIME(TIMEToDetik(T)-N2));
}

long Durasi (TIME TAw, TIME TAkh) {
    return ((TIMEToDetik(TAkh)-TIMEToDetik(TAw))%86400);
}

