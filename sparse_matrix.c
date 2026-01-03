#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int uretilecekDegerler[] = {20, 10, 55, 59};
    int satirSayisi = 5, sutunSayisi = 5;
    int i, j;

    /* Normal matris (dinamik) */
    int **matris = (int **)malloc(satirSayisi * sizeof(int *));
    for(i = 0; i < satirSayisi; i++)
        matris[i] = (int *)calloc(sutunSayisi, sizeof(int));

    /* Degerleri matrise yerlestir */
    matris[0][2] = uretilecekDegerler[0];
    matris[1][4] = uretilecekDegerler[1];
    matris[3][0] = uretilecekDegerler[2];
    matris[4][3] = uretilecekDegerler[3];

    /* Sifir olmayan eleman sayisini bul */
    int adet = 0;
    for(i = 0; i < satirSayisi; i++)
        for(j = 0; j < sutunSayisi; j++)
            if(matris[i][j] != 0)
                adet++;

    /* Sparse matris */
    int **sparse = (int **)malloc((adet + 1) * sizeof(int *));
    for(i = 0; i <= adet; i++)
        sparse[i] = (int *)malloc(3 * sizeof(int));

    /* Baslik bilgisi */
    sparse[0][0] = satirSayisi;
    sparse[0][1] = sutunSayisi;
    sparse[0][2] = adet;

    int index = 1;

    /* Sparse donusum */
    for(i = 0; i < satirSayisi; i++) {
        for(j = 0; j < sutunSayisi; j++) {
            if(matris[i][j] != 0) {
                sparse[index][0] = i;
                sparse[index][1] = j;
                sparse[index][2] = matris[i][j];
                index++;
            }
        }
    }

    /* Yazdirma */
    printf("SATIR\tSUTUN\tDEGER\n");
    for(i = 0; i <= adet; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    /* Bellek temizleme */
    for(i = 0; i < satirSayisi; i++)
        free(matris[i]);
    free(matris);

    for(i = 0; i <= adet; i++)
        free(sparse[i]);
    free(sparse);

    return 0;
}
