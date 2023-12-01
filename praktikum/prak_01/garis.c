#include <stdio.h>
#include <math.h>
#include "point.h"
#include "garis.h"
#include "boolean.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L) {
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while (EQ(P1, P2)) {
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    CreateGaris(L, P1, P2);
}

void TulisGARIS (GARIS L) {
    POINT P1 = PAwal(L);
    POINT P2 = PAkhir(L);
    float x1 = Absis(P1);
    float y1 = Ordinat(P1);
    float x2 = Absis(P2);
    float y2 = Ordinat(P2);
    printf("((%.2f,%.2f),(%.2f,%.2f))", x1, y1, x2, y2);
}

float PanjangGARIS (GARIS L) {
    float x1 = Absis(PAwal(L)), y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L)), y2 = Ordinat(PAkhir(L));
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

float Gradien (GARIS L) {
    float x1 = Absis(PAwal(L)), y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L)), y2 = Ordinat(PAkhir(L));
    return ((y2-y1)/(x2-x1));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY) {
    POINT P1 = PAwal(*L);
    POINT P2 = PAkhir(*L);
    Geser(&P1, deltaX, deltaY);
    Geser(&P2, deltaX, deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2) {
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2) {
    return (Gradien(L1) == Gradien(L2));
}

float JarakGARIS (GARIS L, POINT P) {
    float x1 = Absis(PAwal(L)), y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L)), y2 = Ordinat(PAkhir(L));

    float xp = Absis(P), yp = Ordinat(P);

    float m, c, d;
    m = (y2-y1)/(x2-x1);
    c = m*(-x1) + y1;
    d = (m*xp-yp+c)/(sqrt(m*m+1));
    if (d<0) {
        d*=(-1);
    }
    return d;
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P) {
    return (JarakGARIS(L, P) == 0);
}

// int main() {
//     GARIS *L1, *L2;
//     BacaGARIS(L1);
//     TulisGARIS(*L1);
//     BacaGARIS(L2);
//     TulisGARIS(*L2);
//     printf("%f", PanjangGARIS(*L1));
//     printf("%f", Gradien(*L2));
//     printf("%c", IsTegakLurus(*L1, *L2));
// }