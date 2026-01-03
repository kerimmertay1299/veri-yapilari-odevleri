#include <stdio.h>
#include <ctype.h>

#define BOYUT 100

/* Operatorlerin oncelik sirasi */
int oncelikSirasi(char isaret) {
    if (isaret == '+' || isaret == '-') return 1;
    if (isaret == '*' || isaret == '/') return 2;
    return 0;
}

/* Stack'e eleman ekleme */
void ekle(char yigin[], int *tepe, char eleman) {
    (*tepe)++;
    yigin[*tepe] = eleman;
}

/* Stack'ten eleman cikarma */
char cikar(char yigin[], int *tepe) {
    char temp = yigin[*tepe];
    (*tepe)--;
    return temp;
}

/* Stack'in en ustundeki elemani gosterir */
char ustEleman(char yigin[], int tepe) {
    return yigin[tepe];
}

/* Shunting Yard algoritmasi kullanilarak infix ifadeyi postfix'e cevirir */
void infixPostfixDonusum(char infix[], char postfix[]) {

    char operatorYigini[BOYUT];
    int tepe = -1;
    int i = 0, j = 0;

    /* Infix ifade tek tek kontrol edilir */
    while (infix[i] != '\0') {

        /* Harf veya rakam ise direkt postfix'e eklenir */
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        /* Acilan parantez stack'e atilir */
        else if (infix[i] == '(') {
            ekle(operatorYigini, &tepe, infix[i]);
        }

        /* Kapanan parantez gelirse '(' gorene kadar stack bosaltilir */
        else if (infix[i] == ')') {
            while (tepe != -1 && ustEleman(operatorYigini, tepe) != '(') {
                postfix[j++] = cikar(operatorYigini, &tepe);
            }
            cikar(operatorYigini, &tepe); /* '(' silinir */
        }

        /* Operator geldiyse oncelik kontrolu yapilir */
        else {
            while (tepe != -1 &&
                   oncelikSirasi(ustEleman(operatorYigini, tepe)) >=
                   oncelikSirasi(infix[i])) {
                postfix[j++] = cikar(operatorYigini, &tepe);
            }
            ekle(operatorYigini, &tepe, infix[i]);
        }
        i++;
    }

    /* Stack'te kalan operatorler postfix'e eklenir */
    while (tepe != -1) {
        postfix[j++] = cikar(operatorYigini, &tepe);
    }

    postfix[j] = '\0';
}

int main() {

    /* Proje icin secilmis ornek ifade */
    char infixIfade[] = "(A+B)*(C-D/E)+F";
    char postfixIfade[BOYUT];

    infixPostfixDonusum(infixIfade, postfixIfade);

    printf("Infix Ifade  : %s\n", infixIfade);
    printf("Postfix Ifade: %s\n", postfixIfade);

    return 0;
}
