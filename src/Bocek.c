/* Bocek.c */
#include "Bocek.h"
#include "Canli.h"
#include <stdio.h>
#include <stdlib.h>

char* bocek_gorunum(struct CANLI* canli) {
    return "C";
}

void bocek_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum) {
    canli->gorunum = (*yeni_gorunum)(canli)[0];
}

struct BOCEK* bocek_olustur(int deger) {
    struct BOCEK* bocek = malloc(sizeof(struct BOCEK));
    bocek->canli = *canli_olustur(deger, bocek_gorunum, bocek_gorunum_degistir);
    return bocek;
}

void bocek_sil(struct BOCEK* bocek) {
    canli_sil(&bocek->canli);
    free(bocek);
}