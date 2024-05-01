/* Canli.c */
#include "Canli.h"
#include <stdlib.h>
#include <string.h>

struct CANLI* canli_olustur(int deger, GORUNUM_FONKSIYONU gorunum, void (*gorunum_degistir)(struct CANLI*, GORUNUM_FONKSIYONU)) {
    struct CANLI* canli = malloc(sizeof(struct CANLI));
    canli->deger = deger;
    canli->gorunum = gorunum(canli)[0];
    canli->gorunum_degistir = gorunum_degistir;
    return canli;
}

void canli_sil(struct CANLI* canli) {
    free(canli);
}
