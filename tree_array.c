#include <stdio.h>

#define BOYUT 15

/* Tree array ile tutuluyor
   index 0 bos birakildi  */

int agac[BOYUT] = {0};

/* Dugum ekleme (binary tree mantigi) */
void dugumEkle(int index, int deger) {
    if (index >= BOYUT) {
        return;
    }
    agac[index] = deger;
}

/* Tree traversal – Preorder */
void preorder(int index) {
    if (index >= BOYUT || agac[index] == 0)
        return;

    printf("%d ", agac[index]);
    preorder(2 * index);
    preorder(2 * index + 1);
}

/* Tree traversal – Inorder */
void inorder(int index) {
    if (index >= BOYUT || agac[index] == 0)
        return;

    inorder(2 * index);
    printf("%d ", agac[index]);
    inorder(2 * index + 1);
}

/* Tree traversal – Postorder */
void postorder(int index) {
    if (index >= BOYUT || agac[index] == 0)
        return;

    postorder(2 * index);
    postorder(2 * index + 1);
    printf("%d ", agac[index]);
}

int main() {

    dugumEkle(1, 20);   // root
    dugumEkle(2, 10);
    dugumEkle(3, 55);
    dugumEkle(4, 5);
    dugumEkle(5, 15);
    dugumEkle(6, 50);
    dugumEkle(7, 59);

    printf("Preorder  : ");
    preorder(1);

    printf("\nInorder   : ");
    inorder(1);

    printf("\nPostorder : ");
    postorder(1);

    return 0;
}
