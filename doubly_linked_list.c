#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum *onceki;
    struct Dugum *sonraki;
};

/* Yeni dugum olusturma */
struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;
    return yeni;
}

/* Listenin sonuna ekleme */
void sonaEkle(struct Dugum** bas, int veri) {
    struct Dugum* yeni = dugumOlustur(veri);

    if (*bas == NULL) {
        *bas = yeni;
        return;
    }

    struct Dugum* gecici = *bas;
    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;

    gecici->sonraki = yeni;
    yeni->onceki = gecici;
}

/* Araya ekleme (belirli bir degerden sonra) */
void arayaEkle(struct Dugum* bas, int oncekiVeri, int yeniVeri) {
    struct Dugum* gecici = bas;

    while (gecici != NULL && gecici->veri != oncekiVeri)
        gecici = gecici->sonraki;

    if (gecici == NULL)
        return;

    struct Dugum* yeni = dugumOlustur(yeniVeri);

    yeni->sonraki = gecici->sonraki;
    yeni->onceki = gecici;

    if (gecici->sonraki != NULL)
        gecici->sonraki->onceki = yeni;

    gecici->sonraki = yeni;
}

/* Dugum silme (veriye gore) */
void dugumSil(struct Dugum** bas, int silinecekVeri) {
    struct Dugum* gecici = *bas;

    while (gecici != NULL && gecici->veri != silinecekVeri)
        gecici = gecici->sonraki;

    if (gecici == NULL)
        return;

    if (gecici->onceki != NULL)
        gecici->onceki->sonraki = gecici->sonraki;
    else
        *bas = gecici->sonraki;

    if (gecici->sonraki != NULL)
        gecici->sonraki->onceki = gecici->onceki;

    free(gecici);
}

/* Ileri dogru traversal */
void ileriTraversal(struct Dugum* bas) {
    struct Dugum* gecici = bas;
    while (gecici != NULL) {
        printf("%d ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("\n");
}

/* Geri dogru traversal */
void geriTraversal(struct Dugum* bas) {
    struct Dugum* gecici = bas;

    if (gecici == NULL)
        return;

    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;

    while (gecici != NULL) {
        printf("%d ", gecici->veri);
        gecici = gecici->onceki;
    }
    printf("\n");
}

int main() {

    struct Dugum* bas = NULL;

    /* Ogrenci numarasindan turetilmis veriler */
    sonaEkle(&bas, 20);
    sonaEkle(&bas, 10);
    sonaEkle(&bas, 55);
    sonaEkle(&bas, 59);

    printf("Ilk Liste (Ileri): ");
    ileriTraversal(bas);

    arayaEkle(bas, 10, 25);
    printf("Araya Ekleme Sonrasi: ");
    ileriTraversal(bas);

    dugumSil(&bas, 55);
    printf("Silme Sonrasi (Ileri): ");
    ileriTraversal(bas);

    printf("Silme Sonrasi (Geri): ");
    geriTraversal(bas);

    return 0;
}
