/* Canli.c */
#include "Canli.h"
#include <stdlib.h>

struct CANLI* canli_olustur(int deger, char* (*gorunum)(struct CANLI*)) {
    struct CANLI* canli = malloc(sizeof(struct CANLI));
    canli->deger = deger;
    canli->gorunum = (*gorunum)(canli)[0]; // İlk karakteri al
    return canli;
}

void canli_sil(struct CANLI* canli) {
    free(canli);
}