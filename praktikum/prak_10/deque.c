#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

/* Prototype manajemen memori */
Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Deque q) {
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
int length(Deque q) {
    Address p;
    int len = 0;
    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        while(p != NIL) {
            len++;
            p = NEXT(p);
        }
    }
    return len;
}
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateDeque(Deque *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayDeque(Deque q) {
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
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void EnqueueHead(Deque *q, ElType x) {
    Address new;
    new = newNode(x);
    if (new != NIL) {
        if (isEmpty(*q)) {
            ADDR_TAIL(*q) = new;
        } else {
            NEXT(new) = ADDR_HEAD(*q);
        }
        ADDR_HEAD(*q) = new;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
void DequeueHead(Deque *q, ElType *x) {
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
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
void EnqueueTail(Deque *q, ElType x) {
    Address p;
    if (isEmpty(*q)) {
        EnqueueHead(q, x);
    } else {
        p = newNode(x);
        if (p != NIL) {
            NEXT(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
void DequeueTail(Deque *q, ElType *x) {
    Address p;
    *x = TAIL(*q);
    p = ADDR_HEAD(*q);
    while (NEXT(p) != ADDR_TAIL(*q)) {
        p = NEXT(p);
    }
    ADDR_TAIL(*q) = p;
    free(NEXT(p));
}
/* Proses: Menghapus x pada bagian TAIL dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteLast */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen TAIL pd I.S., TAIL "maju" */