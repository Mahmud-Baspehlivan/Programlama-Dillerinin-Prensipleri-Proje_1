/* Sinek.c */
#include "Sinek.h"
#include "Bocek.h"
#include <stdio.h>
#include <stdlib.h>

char* sinek_gorunum(struct CANLI* canli) {
    return "S";
}

void sinek_hayatta_kal(struct CANLI* canli) {
    // Sinek için hayatta kalma mantığı
}

void sinek_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum) {
    canli->gorunum = (*yeni_gorunum)(canli)[0];
}

struct SINEK* sinek_olustur(int deger) {
    struct SINEK* sinek = malloc(sizeof(struct SINEK));
    sinek->bocek.canli = *canli_olustur(deger, sinek_gorunum, sinek_hayatta_kal, sinek_gorunum_degistir);
    return sinek;
}

void sinek_sil(struct SINEK* sinek) {
    canli_sil(&sinek->bocek.canli);
    free(sinek);
}