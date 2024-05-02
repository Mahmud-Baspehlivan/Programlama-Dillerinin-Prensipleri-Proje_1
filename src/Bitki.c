/* Bitki.c */
#include "Bitki.h"
#include <stdio.h>
#include <stdlib.h>

char* bitki_gorunum(struct CANLI* canli) {
    return "B";
}

struct BITKI* bitki_olustur(int deger) {
    struct BITKI* bitki = malloc(sizeof(struct BITKI));
    bitki->canli = *canli_olustur(deger, bitki_gorunum);
    return bitki;
}

void bitki_sil(struct BITKI* bitki) {
    canli_sil(&bitki->canli);
    free(bitki);
}