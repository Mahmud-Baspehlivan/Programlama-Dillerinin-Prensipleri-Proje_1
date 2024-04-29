/* Bitki.c */
#include "Bitki.h"
#include <stdio.h>
#include <stdlib.h>

char* bitki_gorunum(struct CANLI* canli) {
    char* gorunum = malloc(sizeof(char) * 2);
    gorunum[0] = 'B';
    gorunum[1] = '\0';
    return gorunum;
}

char* bitki_yenildi_gorunum(struct CANLI* canli) {
    char* gorunum = malloc(sizeof(char) * 2);
    gorunum[0] = 'X';
    gorunum[1] = '\0';
    return gorunum;
}

void bitki_hayatta_kal(struct CANLI* canli) {
    // Bitki hayatta kalma mantığı...
}

void bitki_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum) {
    canli->gorunum = (*yeni_gorunum)(canli)[0];
}

struct BITKI* bitki_olustur(int deger) {
    struct BITKI* bitki = malloc(sizeof(struct BITKI));
    bitki->canli = *canli_olustur(deger, bitki_gorunum, bitki_hayatta_kal, bitki_gorunum_degistir);
    return bitki;
}

void bitki_sil(struct BITKI* bitki) {
    canli_sil(&bitki->canli);
    free(bitki);
}
