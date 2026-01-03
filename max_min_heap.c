#include <stdio.h>

#define BOYUT 9

/* -------- MAX HEAP -------- */

void maxHeapify(int dizi[], int n, int i) {
    int enBuyuk = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && dizi[sol] > dizi[enBuyuk])
        enBuyuk = sol;

    if (sag < n && dizi[sag] > dizi[enBuyuk])
        enBuyuk = sag;

    if (enBuyuk != i) {
        int temp = dizi[i];
        dizi[i] = dizi[enBuyuk];
        dizi[enBuyuk] = temp;

        maxHeapify(dizi, n, enBuyuk);
    }
}

void maxHeapOlustur(int dizi[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(dizi, n, i);
}

/* -------- MIN HEAP -------- */

void minHeapify(int dizi[], int n, int i) {
    int enKucuk = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && dizi[sol] < dizi[enKucuk])
        enKucuk = sol;

    if (sag < n && dizi[sag] < dizi[enKucuk])
        enKucuk = sag;

    if (enKucuk != i) {
        int temp = dizi[i];
        dizi[i] = dizi[enKucuk];
        dizi[enKucuk] = temp;

        minHeapify(dizi, n, enKucuk);
    }
}

void minHeapOlustur(int dizi[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(dizi, n, i);
}

/* -------- YARDIMCI -------- */

void yazdir(int dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", dizi[i]);
    printf("\n");
}

int main() {

  
    int veri[BOYUT] = {20, 10, 55, 59, 2, 1, 0, 5, 9};

    int maxHeap[BOYUT];
    int minHeap[BOYUT];

    for (int i = 0; i < BOYUT; i++) {
        maxHeap[i] = veri[i];
        minHeap[i] = veri[i];
    }

    maxHeapOlustur(maxHeap, BOYUT);
    minHeapOlustur(minHeap, BOYUT);

    printf("Max Heap: ");
    yazdir(maxHeap, BOYUT);

    printf("Min Heap: ");
    yazdir(minHeap, BOYUT);

    return 0;
}
