/* Pire.c */
#include "Pire.h"
#include "Bocek.h"
#include <stdio.h>
#include <stdlib.h>

char* pire_gorunum(struct CANLI* canli) {
    return "P";
}

struct PIRE* pire_olustur(int deger) {
    struct PIRE* pire = malloc(sizeof(struct PIRE));
    pire->bocek.canli = *canli_olustur(deger, pire_gorunum);
    return pire;
}

void pire_sil(struct PIRE* pire) {
    canli_sil(&pire->bocek.canli);
    free(pire);
}