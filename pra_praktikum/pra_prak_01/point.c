#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

void CreatePoint (POINT *P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT *P) {
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT (POINT P) {
    float x, y;
    x = Absis(P);
    y = Ordinat(P);
    printf("(%f,%f)", x, y);
}

boolean EQ (POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
    return !EQ(P1, P2);
}

boolean IsOrigin (POINT P) {
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P) {
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    if (Ordinat(P) > 0) {
        if (Absis(P) > 0) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (Absis(P) > 0) {
            return 4;
        } else {
            return 3;
        }
    }
}

POINT NextX (POINT P) {
    Absis(P) += 1;
    return P;
}

POINT NextY (POINT P) {
    Absis(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX) {
    if (SbX) {
        Ordinat(P) *= (-1);
    } else {
        Absis(P) *= (-1);
    }
    return P;
}

float Jarak0 (POINT P) {
    float deltaX = Absis(P);
    float deltaY = Ordinat(P);
    double leng = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    float panjang = leng;
    return panjang;
}

float Panjang (POINT P1, POINT P2) {
    float deltaX = Absis(P1)-Absis(P2);
    float deltaY = Ordinat(P1)-Ordinat(P2);
    double leng = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    float panjang = leng;
    return panjang;
}

void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) = Ordinat(*P)*(-1);
    } else {
        Absis(*P) = Absis(*P)*(-1);
    }
}

void Putar (POINT *P, float Sudut) {
    float x = Absis(*P);
    float y = Ordinat(*P);

    while (180 <= Sudut <= -179) {
        if (Sudut > 180) {
            Sudut -= 360;
        } else {
            Sudut += 360;
        }
    }

    float rad = Sudut/360*3.14;
    Absis(*P) = cos(rad)*x - sin(rad)*y;
    Ordinat(*P) = sin(rad)*x + cos(rad)*y;
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) {
    int a, b;
    a = (Ordinat(P2)-Ordinat(P1))/(Absis(P2)-Absis(P1));
    b = a*(-Absis(P1))+Ordinat(P1);
    printf("(%d,%d)", a, b);
}