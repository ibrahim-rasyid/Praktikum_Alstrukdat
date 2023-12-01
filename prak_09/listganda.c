#include <stdio.h>
#include "listganda.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(ElType));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
}

void createListGanda(ListGanda *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    CURRENT(*l) = NULL;
}

boolean isEmpty(ListGanda l) {
    return (CURRENT(l) == NULL);
}
/* Mengirim true jika list kosong */

boolean isOneElement(ListGanda l) {
    return (NEXT(CURRENT(l)) == CURRENT(l));
}
/* Mengirim true jika list terdiri atas 1 elemen saja*/

int length(ListGanda l) {
    if (isEmpty(l)) {
        return 0;
    } else if (isOneElement(l)) {
        return 1;
    } else {
        int len = 0;
        Address p = CURRENT(l);
        while (p != CURRENT(l)) {
            len++;
            p = NEXT(p);
        }
        return len;
    }
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void rotate(ListGanda *l, int k) {
    int i;
    Address p = CURRENT(*l);
    if (p != NULL) {
        if (k > 0) {
            for (i=0; i<k; i++) {
                p = NEXT(p);
            }
        } else if (k < 0) {
            for (i=0; i>k; i--) {
                p = PREV(p);
            }
        }
        CURRENT(*l) = p;
    }
}
/* I.S. l terdefinisi, l mungkin kosong
    k mungkin positif, nol, maupun negatif, abs(k) mungkin lebih besar dari length(l) */
/* F.S. CURRENT menunjuk ke elemen ke-k dari CURRENT sebelumnya
    dengan k positif artinya ke arah NEXT dan k negatif artinya ke arah PREV */

void insertAfterCurrent(ListGanda *l, ElType x) {
    Address p, e;
    e = newNode(x);
    p = CURRENT(*l);
    if (isEmpty(*l)) {
        NEXT(e) = e;
        PREV(e) = e;
    } else {
        NEXT(e) = NEXT(p);
        PREV(e) = p;
        PREV(NEXT(e)) = e;
        NEXT(p) = e;
    }
    CURRENT(*l) = e;
}
/* I.S. l terdefinisi, l mungkin kosong */
/* F.S.
    1. Terbentuk node baru E,
    2. E disisipkan pada NEXT dari CURRENT,
    3. CURRENT menunjuk ke E
 */

void deleteCurrent(ListGanda *l, ElType *x) {
    Address p = CURRENT(*l);
    if (isOneElement(*l)) {
        CURRENT(*l) = NULL;
    } else {
        NEXT(PREV(p)) = NEXT(p);
        PREV(NEXT(p)) = PREV(p);
        CURRENT(*l) = NEXT(p);
    }
    free(p);
}
/* I.S. l terdefinisi, l tidak kosong */
/* F.S.
    1. Elemen CURRENT (E) dikeluarkan dari list,
    2. CURRENT menunjuk pada NEXT dari E
    3. x berisi nilai E
    4. E dihapus
 */