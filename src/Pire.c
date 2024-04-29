/* Pire.c */
#include "Pire.h"
#include "Bocek.h"
#include <stdio.h>
#include <stdlib.h>

char* pire_gorunum(struct CANLI* canli) {
    return "P";
}
void pire_hayatta_kal(struct CANLI* canli) {
    // Pire için hayatta kalma mantığı
}

void pire_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum) {
    canli->gorunum = (*yeni_gorunum)(canli)[0];
}

struct PIRE* pire_olustur(int deger) {
    struct PIRE* pire = malloc(sizeof(struct PIRE));
    pire->bocek.canli = *canli_olustur(deger, pire_gorunum, pire_hayatta_kal, pire_gorunum_degistir);
    return pire;
}

void pire_sil(struct PIRE* pire) {
    canli_sil(&pire->bocek.canli);
    free(pire);
}