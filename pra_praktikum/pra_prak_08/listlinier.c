#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx) {
    Address p = l;
    int i = 0;
    while (i<idx) {
        i++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    Address p = *l;
    int i = 0;
    while (i<idx) {
        i++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    int idx = 0;
    boolean found = false;
    Address p = l;
    while ((p != NULL) && (!found)) {
        if (INFO(p) == val) {
            found = true;
        } else {
            p = NEXT(p);
            idx++;
        }
    }
    if (!found) {
        idx = IDX_UNDEF;
    }
    return idx;
}

void insertFirst(List *l, ElType val) {
    Address newP;
    newP = newNode(val);
    if (newP != NULL) {
        NEXT(newP) = *l;
        *l = newP;
    }
}

void insertLast(List *l, ElType val) {
    Address p, newP;
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        newP = newNode(val);
        if (newP != NULL) {
            p = *l;
            while (NEXT(p) != NULL) {
                p = NEXT(p);
            }
            NEXT(p) = newP;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    Address p, newP;
    int i = 0;
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        newP = newNode(val);
        if (newP != NULL) {
            p = *l;
            while (i<idx-1) {
                p = NEXT(p);
                i++;
            }
            NEXT(newP) = NEXT(p);
            NEXT(p) = newP;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = *l, del = NULL;
    while (NEXT(p) != NULL) {
        del = p;
        p = NEXT(p);
    }
    if (del == NULL) {
        *l = NULL;
    } else {
        NEXT(del) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    Address p, del;
    int i = 0;
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        p = *l;
        while (i<idx-1) {
            i++;
            p = NEXT(p);
        }
        del = NEXT(p);
        *val = INFO(del);
        NEXT(p) = NEXT(del);
        free(del);
    }
}

void displayList(List l) {
    boolean comma = false;
    Address p = l;
    printf("[");
    while (p != NULL) {
        if (comma) {
            printf(",");
        } else {
            comma = true;
        }
        printf("%d", INFO(p));
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
    int len = 0;
    Address p = l;
    while (p != NULL) {
        len++;
        p = NEXT(p);
    }
    return len;
}

List concat(List l1, List l2) {
    Address p;
    List l3;
    CreateList(&l3);

    p = l1;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}