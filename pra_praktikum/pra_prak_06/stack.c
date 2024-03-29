#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// Nilai Pra-Praktikum : 90/100

void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S) {
    return Top(S) == Nil;
}

boolean IsFull(Stack S) {
    return Top(S) == MaxEl-1;
}

void Push(Stack * S, infotype X) {
    if (IsEmpty(*S)) {
        Top(*S) = 1;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
}

void Pop(Stack * S, infotype* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}