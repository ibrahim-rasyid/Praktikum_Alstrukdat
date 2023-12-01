#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x) {
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(List l) {
    return (l == NIL);
}

boolean isOneElmt(List l) {
    return (!isEmpty(l) && NEXT(l) == NIL);
}

ElType head(List l) {
    return (INFO(l));
}

List tail(List l) {
    return (NEXT(l));
}

List konso(List l, ElType e) {
    Address p;

    p = newNode(e);
    if (p == NIL) {
        return l;
    } else {
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return (konso(copy(tail(l)), head(l)));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return (1 + length(tail(l)));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d ", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx) {
    if (idx < 1) {
        return konso(l, e);
    } else {
        return konso(insertAt(tail(l), e, idx-1), head(l));
    }
}

List deleteFirst(List l) {
    return tail(l);
}

List deleteAt(List l, int idx) {
    if (idx < 1) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(tail(l), idx-1), head(l));
    }
}

List deleteLast(List l) {
    return deleteAt(l, length(l)-1);
}

List inverseList (List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return (konsb(inverseList(tail(l)), head(l)));
    }
}

void splitPosNeg (List l, List *l1, List *l2) {
    if (isEmpty(l)) {
        return;
    }
    if (head(l) >= 0) {
        *l1 = konsb(*l1, head(l));
    } else {
        *l2 = konsb(*l2, head(l));
    }
    splitPosNeg(tail(l), l1, l2);
}

void splitOnX (List l, ElType x, List *l1, List *l2) {
    if (isEmpty(l)) {
        return;
    }
    if (head(l) < x) {
        *l1 = konsb(*l1, head(l));
    } else {
        *l2 = konsb(*l2, head(l));
    }
    splitOnX(tail(l), x, l1, l2);
}

List removeDuplicate(List l, List unique) {
    if (!isEmpty(l)) {
        if (!isMember(unique, head(l))) {
            return (removeDuplicate(tail(l), konso(unique, head(l))));
        } else {
            return (removeDuplicate(tail(l), unique));
        }
    } else {
        return NIL;
    }
}

// int main() {
//     List bruh = NIL;
//     List l1 = NIL, l2 = NIL;
//     bruh = newNode(1);
//     l1 = newNode(0);
//     l2 = newNode(0);
//     konsb(bruh, -1);
//     konsb(bruh, 3);
//     konsb(bruh, -5);
//     konsb(bruh, -2);
//     konsb(bruh, 2);
//     displayList(bruh);
//     printf("\n");
//     splitOnX(bruh, 2, &l1, &l2);
//     displayList(bruh);
//     printf("\n");
//     displayList(l1);
//     printf("\n");
//     displayList(l2);
//     printf("\n");
// }