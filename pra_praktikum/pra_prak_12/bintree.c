#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

// Nilai Pra-Praktikum : 100/100

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) { 
    BinTree p;
    p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = root;
        RIGHT(p) = right_tree;
        LEFT(p) = left_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
    Address p;
    p = (Address) malloc(sizeof(ElType));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p) {
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    return (p == NULL);
}

boolean isOneElmt (BinTree p) {
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL);
}

boolean isUnerLeft (BinTree p) {
    return (LEFT(p) != NULL && RIGHT(p) == NULL);
}

boolean isUnerRight (BinTree p) {
    return (LEFT(p) == NULL && RIGHT(p) != NULL);
}

boolean isBinary (BinTree p) {
    return (LEFT(p) != NULL && RIGHT(p) != NULL);
}

void printPreorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeLevel(BinTree p, int h, int l) {
    /* l adalah level atau kedalaman saat ini */
    int i;
    if (!isTreeEmpty(p)) {
        for (i=0; i<h*l; i++) {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeLevel(LEFT(p), h, l+1);
        printTreeLevel(RIGHT(p), h, l+1);
    }
}

void printTree(BinTree p, int h) {
    printTreeLevel(p, h, 0);
}