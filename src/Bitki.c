/* Bitki.c */
#include "Bitki.h"
#include <stdio.h>
#include <stdlib.h>

char* bitki_gorunum(struct CANLI* canli) {
        return "B";
}

char* bitki_yenildi_gorunum(struct CANLI* canli) {
        return "X";
}

void bitki_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum) {
    canli->gorunum = (*yeni_gorunum)(canli)[0];
}

struct BITKI* bitki_olustur(int deger) {
    struct BITKI* bitki = malloc(sizeof(struct BITKI));
    bitki->canli = *canli_olustur(deger, bitki_gorunum, bitki_gorunum_degistir);
    return bitki;
}

void bitki_sil(struct BITKI* bitki) {
    canli_sil(&bitki->canli);
    free(bitki);
}
