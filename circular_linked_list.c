#include <stdio.h>
#include <stdlib.h>


/* Cembersel Linked List dugumu */
struct Dugum {
    int veri;
    struct Dugum *sonraki;
};

/* Yeni dugum olusturma */
struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->sonraki = yeni;  // cembersel baglanti
    return yeni;
}

/* Sona ekleme */
void sonaEkle(struct Dugum** bas, int veri) {
    struct Dugum* yeni = dugumOlustur(veri);

    if (*bas == NULL) {
        *bas = yeni;
        return;
    }

    struct Dugum* gecici = *bas;
    while (gecici->sonraki != *bas)
        gecici = gecici->sonraki;

    gecici->sonraki = yeni;
    yeni->sonraki = *bas;
}

/* Araya ekleme (belirli bir degerden sonra) */
void arayaEkle(struct Dugum* bas, int oncekiVeri, int yeniVeri) {
    struct Dugum* gecici = bas;

    if (bas == NULL)
        return;

    do {
        if (gecici->veri == oncekiVeri) {
            struct Dugum* yeni = dugumOlustur(yeniVeri);
            yeni->sonraki = gecici->sonraki;
            gecici->sonraki = yeni;
            return;
        }
        gecici = gecici->sonraki;
    } while (gecici != bas);
}

/* Dugum silme (veriye gore) */
void dugumSil(struct Dugum** bas, int silinecekVeri) {
    if (*bas == NULL)
        return;

    struct Dugum *gecici = *bas, *onceki = NULL;

    /* Tek dugum varsa */
    if (gecici->veri == silinecekVeri && gecici->sonraki == *bas) {
        free(gecici);
        *bas = NULL;
        return;
    }

    do {
        onceki = gecici;
        gecici = gecici->sonraki;
    } while (gecici != *bas && gecici->veri != silinecekVeri);

    if (gecici->veri != silinecekVeri)
        return;

    onceki->sonraki = gecici->sonraki;

    if (gecici == *bas)
        *bas = gecici->sonraki;

    free(gecici);
}

/* Traversal (tek tur doner) */
void traversal(struct Dugum* bas) {
    if (bas == NULL)
        return;

    struct Dugum* gecici = bas;
    do {
        printf("%d ", gecici->veri);
        gecici = gecici->sonraki;
    } while (gecici != bas);

    printf("\n");
}

int main() {

    struct Dugum* bas = NULL;

    
    sonaEkle(&bas, 20);
    sonaEkle(&bas, 10);
    sonaEkle(&bas, 55);
    sonaEkle(&bas, 59);

    printf("Ilk Liste: ");
    traversal(bas);

    arayaEkle(bas, 10, 25);
    printf("Araya Ekleme Sonrasi: ");
    traversal(bas);

    dugumSil(&bas, 55);
    printf("Silme Sonrasi: ");
    traversal(bas);

    return 0;
}
