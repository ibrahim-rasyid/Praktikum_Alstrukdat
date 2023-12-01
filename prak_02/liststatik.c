#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    int i = 0;
    for (i;i<CAPACITY;i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int count = 0, i = 0;
    for (i;i<CAPACITY;i++) {
        if (ELMT(l, i) != MARK) {
            count++;
        }
    }
    return count;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    return (listLength(l)-1);
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (IDX_MIN<=i && i<=CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    int idx_first = getFirstIdx(l);
    int idx_last = getLastIdx(l);
    return (idx_first <= i && i <= idx_last);
}

boolean isEmpty(ListStatik l) {
    return listLength(l) == 0;
}

boolean isFull(ListStatik l) {
    return listLength(l) == CAPACITY;
}

void readList(ListStatik *l) {
    int n;
    scanf("%d", &n);
    while (!(isIdxValid(*l, n))) {
        scanf("%d", &n);
    }
    CreateListStatik(l);
    int i;
    int el;
    for (i=IDX_MIN; i<n; i++) {
        scanf("%d", &el);
        ELMT(*l, i) = el;
    }
}

void printList(ListStatik l) {
    printf("[");
    int i;
    for (i=0; i<CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            if (i == 0) {
                printf("%d", ELMT(l, i));
            } else {
                printf(",%d", ELMT(l, i));
            }
        }
    }
    printf("]\n");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik *l3;
    CreateListStatik(l3);
    int i = IDX_MIN;
    for (i; i < CAPACITY; i++) {
        if (plus) {
            ELMT(*l3, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(*l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return *l3;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    int i = IDX_MIN;
    boolean con = true;
    for (i; i < CAPACITY; i++) {
        if (ELMT(l1, i) == ELMT(l2, i)) {
            con = false;
        }
    }
    return con;
}

int indexOf(ListStatik l, ElType val) {
    int i = IDX_MIN;
    boolean find = true;
    while (isIdxValid(l, i) && find) {
        if (ELMT(l, i) == val) {
            find = false;
        } else {
            i++;
        }
    }
    if (i == CAPACITY) {
        return IDX_UNDEF;
    } else {
        return i;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int i;
    int maxval = -1000, minval = 1000;
    for (i=0; i<CAPACITY; i++) {
        if (ELMT(l, i) > maxval && ELMT(l, i) != MARK) {
            maxval = ELMT(l, i);
        } else if (ELMT(l, i) < minval && ELMT(l, i) != MARK) {
            minval = ELMT(l, i);
        }
    }
    *max = maxval;
    *min = minval;
}

void insertFirst(ListStatik *l, ElType val) {
    int i = CAPACITY;
    int idx_first = getFirstIdx(*l);
    if (!isFull(*l)) {
        for (i; i>idx_first;i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, idx_first) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    int i = CAPACITY;
    if (!isFull(*l) && !isEmpty(*l) && isIdxValid(*l, idx)) {
        for (i; i>idx;i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, idx) = val;
    }
}

void insertLast(ListStatik *l, ElType val) {
    int idx_last = getLastIdx(*l);
    if (!isFull(*l)) {
        ELMT(*l, idx_last+1) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val) {
    int i = IDX_MIN;
    int idx_first = getFirstIdx(*l), idx_last = getLastIdx(*l);
    if (!isEmpty(*l)) {
        ELMT(*l, idx_first) = MARK;
        for (i; i<idx_last; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    int i = idx;
    int idx_last = getLastIdx(*l);
    if (!isEmpty(*l) && isIdxValid(*l, i)) {
        ELMT(*l, i) = MARK;
        for (i; i<idx_last; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
    }
}

void deleteLast(ListStatik *l, ElType *val) {
    int idx_last = getLastIdx(*l);
    if (!isEmpty(*l)) {
        ELMT(*l, idx_last) = MARK;
    }
}

void sortList(ListStatik *l, boolean asc) {
    int i = getFirstIdx(*l);
    int j;
    int temp;
    for (i; i<CAPACITY; i++) {
        for (j=i+1; j<CAPACITY; j++) {
            if (asc && (ELMT(*l, i) > ELMT(*l, j)) && (ELMT(*l, i) != MARK) && (ELMT(*l, j) != MARK)) {
                temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, j);
                ELMT(*l, j) = temp;
            } else if (!asc && (ELMT(*l, i) < ELMT(*l, j)) && (ELMT(*l, i) != MARK) && (ELMT(*l, j) != MARK)) {
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, i);
                ELMT(*l, i) = temp;
            }
        }
    }
}