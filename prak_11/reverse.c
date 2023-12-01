#include "listrec.h"
#include <stdio.h>

void displayListHorizontal(List l) {
    // KAMUS

    // ALGORITMA
    if (!isEmpty(l)) {
        printf("%d", head(l));
        if (!isOneElmt(l)) {
        	printf(" ");
        }
        displayListHorizontal(tail(l));
    }
}

void partisi(List l, List *lbaru, List *lpart, int panjang, int idx) {
	// KAMUS
	ElType val;

	// ALGORITMA
	if (isEmpty(l)) {
		// *lbaru = concat(*lbaru, *lpart);
		displayListHorizontal(*lpart);
		printf("\n");
	} else {
		*lpart = konso(*lpart, head(l));

		if (idx == 0) {
			idx = panjang;
			// *lbaru = concat(*lbaru, *lpart);
			displayListHorizontal(*lpart);
			printf(" ");
			*lpart = NULL;
			partisi(tail(l), lbaru, lpart, panjang, idx);
		} else {
			partisi(tail(l), lbaru, lpart, panjang, idx - 1);
		}
	}
	// if (idx == 0 || isEmpty(l)) {
	// 	idx = panjang;
	// 	*lbaru = concat(*lbaru, *lpart);
	// 	*lpart = NULL;

	// 	if (!isEmpty(l)) {
	// 		partisi(tail(l), lbaru, lpart, panjang, idx);
	// 	}
	// } else {
	// 	*lpart = konso(*lpart, head(l));
	// 	displayListHorizontal(*lpart);
	// 	partisi(tail(l), lbaru, lpart, panjang, idx - 1);
	// }
}

int main() {
	// KAMUS
	List l, lpart, lbaru;
	int n, k, i;
	ElType inp;

	// ALGORITMA
	l = NULL;
	lbaru = NULL;
	lpart = NULL;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &inp);
		l = konsb(l, inp);
	};

	partisi(l, &lbaru, &lpart, k - 1, k - 1);

	// displayListHorizontal(lbaru);
}