#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (ElType*) malloc(capacity*sizeof(ElType));
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return 0;
}

IdxType getLastIdx(ListDin l) {
    return listLength(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return (i>0 && i<CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return (i>=getFirstIdx(l) && i<=getLastIdx(l));
}

boolean isEmpty(ListDin l) {
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l) {
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l) {
    int n = 0;
    scanf("%d", &n);
    while (n<0 || n>CAPACITY(*l)) {
        scanf("%d", &n);
    }
    CreateListDin(l, CAPACITY(*l));
    NEFF(*l) = n;
    int i = 0, el;
    for (i; i<n; i++) {
        scanf("%d", &el);
        ELMT(*l, i) = el;
    }
}

void printList(ListDin l) {
    int i = 0;
    for (i; i<NEFF(l); i++) {
        if (i == getFirstIdx(l)) {
            printf("[%d", ELMT(l, i));
        } else {
            printf(",%d", ELMT(l,i));
        }
    }
    printf("]\n");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin *l3;
    CreateListDin(l3, CAPACITY(l1));
    int i = 0;
    for (i; i<NEFF(*l3); i++) {
        ELMT(*l3, i) = ELMT(l1, i) + ELMT(l2, i);
    }
    return *l3;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    boolean check = true;
    if (NEFF(l1) != NEFF(l2)) {
        check = false;
    }
    int i = 0;
    while ((i<NEFF(l1)) && check == true) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            check = false;
        }
        i++;
    }
    return check;
}

IdxType indexOf(ListDin l, ElType val) {
    int i = 0;
    boolean found = false;
    int idx;
    while ((i<NEFF(l)) && found == false) {
        if (ELMT(l, i) == val) {
            found = true;
        }
        i++;
    }
    if (i == NEFF(l)) {
        idx = IDX_UNDEF;
    } else {
        idx = i;
    }
    return idx;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    int maxval = -999;
    int minval = 999;
    int i=0;
    for (i; i<NEFF(l); i++) {
        if (ELMT(l, i) > maxval) {
            maxval = ELMT(l, i);
        } else if (ELMT(l, i) < minval) {
            minval = ELMT(l, i);
        }
    }
    *max = maxval;
    *min = minval;
}

void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    int i = 0;
    for (i; i<NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    int i = 0, sum = 0;
    for (i; i<NEFF(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val) {
    int i = 0, count = 0;
    for (i; i<NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            count += 1;
        }
    }
    return count;
}

void sort(ListDin *l, boolean asc) {
    int i = 0, j;
    int temp;
    for (i; i<NEFF(*l); i++) {
        for (j=i+1; j<NEFF(*l); j++) {
            if (asc && (ELMT(*l, i) > ELMT(*l, j))) {
                temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, j);
                ELMT(*l, j) = temp;
            } else if (!asc && (ELMT(*l, i) < ELMT(*l, j))) {
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, i);
                ELMT(*l, i) = temp;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val) {
    NEFF(*l) += 1;
    int idx = NEFF(*l);
    ELMT(*l, idx) = val;
}

void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
    free(val);
}

void expandList(ListDin *l, int num) {
    int cap, neff;
    IdxType i;
    ListDin templist;

    // ALGORITMA
    cap = CAPACITY(*l);
    neff = NEFF(*l);
    copyList(*l, &templist);

    dealocateList(l);

    CreateListDin(l, cap + num);
    NEFF(*l) = neff;

    for (i = 0; i < listLength(*l); i++)
    {
        ELMT(*l, i) = ELMT(templist, i);
    }   
}

void shrinkList(ListDin *l, int num) {
    int cap, neff;
    IdxType i;
    ListDin templist;

    // ALGORITMA
    cap = CAPACITY(*l);
    neff = NEFF(*l);
    copyList(*l, &templist);

    dealocateList(l);

    CreateListDin(l, cap - num);
    NEFF(*l) = neff;

    for (i = 0; i < listLength(*l); i++)
    {
        ELMT(*l, i) = ELMT(templist, i);
    }   
}

void compressList(ListDin *l) {
    int neff;
    IdxType i;
    ListDin templist;

    // ALGORITMA
    neff = NEFF(*l);
    copyList(*l, &templist);

    dealocateList(l);

    CreateListDin(l, neff);
    NEFF(*l) = neff;

    for (i = 0; i < listLength(*l); i++)
    {
        ELMT(*l, i) = ELMT(templist, i);
    }   
}