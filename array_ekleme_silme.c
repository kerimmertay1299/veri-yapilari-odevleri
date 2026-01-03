#include <stdio.h>

#define BOYUT 15

int main() {

    /* Baslangic dizisi  */
    int dizi[BOYUT] = {20, 10, 55, 59, 2};
    int elemanSayisi = 5;

    int i;

    /* -------- DIZIYI YAZDIR -------- */
    printf("Baslangic Dizisi: ");
    for (i = 0; i < elemanSayisi; i++)
        printf("%d ", dizi[i]);
    printf("\n");

    /* -------- ARAYA EKLEME -------- */
    int eklenecekDeger = 25;
    int eklemeIndeksi = 2;   // 2. indise ekleme

    for (i = elemanSayisi; i > eklemeIndeksi; i--)
        dizi[i] = dizi[i - 1];

    dizi[eklemeIndeksi] = eklenecekDeger;
    elemanSayisi++;

    printf("Araya Ekleme Sonrasi: ");
    for (i = 0; i < elemanSayisi; i++)
        printf("%d ", dizi[i]);
    printf("\n");

    /* -------- SILME ISLEMI -------- */
    int silinecekIndeks = 3;   // 3. indisteki elemani sil

    for (i = silinecekIndeks; i < elemanSayisi - 1; i++)
        dizi[i] = dizi[i + 1];

    elemanSayisi--;

    printf("Silme Sonrasi: ");
    for (i = 0; i < elemanSayisi; i++)
        printf("%d ", dizi[i]);
    printf("\n");

    return 0;
}
