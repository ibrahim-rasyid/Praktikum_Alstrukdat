#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"
#include "sort.h"

Address findMiddle(List l) {
    int idx, i;
    Address p;
    
    if (length(l)%2 == 0) {
        idx = (int) length(l)/2;
    } else {
        idx = (int) length(l)/2 + 1;
    }

    p = l;
    for (i=0; i<idx; i++) {
        p = NEXT(p);
    }
    return p;
}

List merge(List l1, List l2) {

}

List mergeSort(List l) {

}

List zigZagSort(List l) {
    
}