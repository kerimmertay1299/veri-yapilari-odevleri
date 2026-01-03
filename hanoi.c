#include <stdio.h>


void kuleCoz(int kalanDisk, char baslangic, char hedef, char ara) {

    if (kalanDisk == 0)
        return;

    kuleCoz(kalanDisk - 1, baslangic, ara, hedef);

    printf("%d numarali disk %c cubugundan %c cubuguna tasindi\n",
           kalanDisk, baslangic, hedef);

    kuleCoz(kalanDisk - 1, ara, hedef, baslangic);
}

int main() {

    int diskAdedi = 5;   
    char kaynakCubuk = 'X';
    char hedefCubuk  = 'Z';
    char araCubuk    = 'Y';

    printf("Hanoi Kuleleri Problemi Cozumu\n");
    printf("Toplam Disk Sayisi: %d\n\n", diskAdedi);

    kuleCoz(diskAdedi, kaynakCubuk, hedefCubuk, araCubuk);

    return 0;
}
