#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack s) {
    return (ADDR_TOP(s) == NIL);
}

int length(Stack s) {
    int len = 0;
    Address p;
    if (!isEmpty(s)) {
        p = ADDR_TOP(s);
        while (p != NIL) {
            len++;
            p = NEXT(p);
        }
    }
    return len;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s) {
    Address p;
    printf("[");
    if (!isEmpty(s)) {
        p = ADDR_TOP(s);
        while (NEXT(p) != NIL) {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }
    printf("]");
}

void push(Stack *s, ElType x) {
    Address p;
    p = newNode(x);
    if (p != NIL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x) {
    Address p;
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    if (length(*s) == 1) {
        ADDR_TOP(*s) = NIL;
    } else {
        ADDR_TOP(*s) = NEXT(p);
    }
    free(p);
}