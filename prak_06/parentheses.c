#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "stack.h"


void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main () {
    Stack S;
    CreateEmpty(&S);

    Word w;
    readWord(&w);

    char kurung;
    int i, count = 1;
    for (i=0; i<(w).Length; i++) {
        if ((w).TabWord[i] == '(') {
            Push(&S, '(');
            if ((w).TabWord[i+1] != ')') {
                count++;
            }
        } else if ((w).TabWord[i] == ')') {
            if (!IsEmpty(S)) {
                Pop(&S, &kurung);
            } else {
                Push(&S, '(');
                break;
            }
        }
    }

    if (IsEmpty(S)) {
        printf("%d\n", count);
    } else {
        printf("%d\n", Nil);
    }
}