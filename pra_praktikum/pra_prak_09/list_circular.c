#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

// Nilai Pra-Praktikum : 87.5/100

boolean isEmpty(List l) {
    return (FIRST(l) == NULL);
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    Address p = (Address) malloc(sizeof(ElmtList));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P) {
    NEXT(P) = NULL;
    free(P);
}

Address search(List l, ElType val) {
    Address p = FIRST(l);
    boolean found = false;
    if (!isEmpty(l)) {
        while (NEXT(p) != FIRST(l) && !found) {
            if (INFO(p) == val) {
                found = true;
            }
            p = NEXT(p);
        }
    }
    if (found) {
        return p;
    } else {
        return NULL;
    }
}

boolean addrSearch(List l, Address p) {
    Address pt = FIRST(l);
    if (isEmpty(l)) {
        return false;
    } else {
        while (NEXT(pt) != FIRST(l) && pt != p){
            pt = NEXT(pt);
        }
        return pt == p;
    }
}

void insertFirst(List *l, ElType val) {
    Address p, newP;
    newP = allocate(val);
    if (newP != NULL) {
        if (isEmpty(*l)) {
            NEXT(newP) = newP;
        } else {
            p = FIRST(*l);
            while (NEXT(p) != FIRST(*l)) {
                p = NEXT(p);
            }
            NEXT(newP) = FIRST(*l);
            NEXT(p) = newP;
        }
        FIRST(*l) = newP;
    }
}

void insertLast(List *l, ElType val) {
    Address p, last;
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = allocate(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType * val) {
    Address p, del;
    del = FIRST(*l);
    *val = INFO(del);
    if (NEXT(del) == FIRST(*l)) {
        FIRST(*l) = NULL;
    } else {
        p = FIRST(*l);
        while (NEXT(p) != FIRST(*l)) {
            p = NEXT(p);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(p) = FIRST(*l);
    }
    deallocate(del);
}

void deleteLast(List *l, ElType * val) {
    Address last, preLast;
    last = FIRST(*l);
    preLast = NULL;
    while (NEXT(last) != FIRST(*l)) {
        preLast = last;
        last = NEXT(last);
    }
    if (preLast == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(preLast) = FIRST(*l);
    }
    *val = INFO(last);
    deallocate(last);
}

void displayList(List l) {
    Address p;
    printf("[");
    if (!isEmpty(l)) {
        p = FIRST(l);
        while (NEXT(p) != FIRST(l)) {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }
    printf("]");
}

// int main () {
//     List l;
//     int val;
//     CreateList(&l);
//     insertLast(&l, 3);
//     insertFirst(&l, 1);
//     insertLast(&l, 6);
//     deleteLast(&l, &val);
//     insertLast(&l, 2);
//     insertLast(&l, 8);
//     insertLast(&l, 9);
//     insertLast(&l, 5);
//     displayList(l);
//     Address p = search(l, 3);
//     printf("%d", p);
// }