#include <stdio.h>
#include "stacklinked.h"

void play(Stack *SAwal, Stack *SAkhir) {
    int val1 = 10, val2 = 10;
    if (isEmpty(*SAwal)) {
        printf("Menara kosong\n");
    } else {
        pop(SAwal, &val1);
        if (!isEmpty(*SAkhir)) {
            pop (SAkhir, &val2);
        }
        if (val1 > val2) {
            printf("Piringan tidak dapat dipindah\n");
            push(SAkhir, val2);
            push(SAwal, val1);
        } else {
            if (val2 != 10) {
                push(SAkhir, val2);
            }
            push(SAkhir, val1);
        }
    }
}

int main() {
    Stack S1, S2, S3;
    int N, Si, Di, i, val1, val2;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&S3);

    push(&S1, 5);
    push(&S1, 4);
    push(&S1, 3);
    push(&S1, 2);
    push(&S1, 1);

    scanf("%d", &N);

    for (i=0; i<N; i++) {
        val1 = 0;
        scanf("%d %d", &Si, &Di);
        if (Si == 1 && Di == 2) {
            play(&S1, &S2);
        } else if (Si == 1 && Di == 3) {
            play(&S1, &S3);
        } else if (Si == 2 && Di == 1) {
            play(&S2, &S1);
        } else if (Si == 2 && Di == 3) {
            play(&S2, &S3);
        } else if (Si == 3 && Di == 1) {
            play(&S3, &S1);
        } else {
            play(&S3, &S2);
        }
    }

    printf("Menara 1: "); DisplayStack(S1); printf("\n");
    printf("Menara 2: "); DisplayStack(S2); printf("\n");
    printf("Menara 3: "); DisplayStack(S3); printf("\n");
}