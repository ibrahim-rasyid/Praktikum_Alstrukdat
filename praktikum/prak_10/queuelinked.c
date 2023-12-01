#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q) {
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}

int length(Queue q) {
    Address p;
    int len = 0;
    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        while (p != NIL) {
            len++;
            p = NEXT(p);
        }
    }
    return len;
}

void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q) {
    Address p;
    printf("[");
    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        while (p != ADDR_TAIL(q)) {
            printf("%d,", INFO(p));
        }
        printf("%d", INFO(p));
    }
    printf("]");
}

void enqueue(Queue *q, ElType x) {
    Address p;
    p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x) {
    Address p;
    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}