/* Bitki.h */
#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    struct CANLI canli;
};

char* bitki_gorunum(struct CANLI* canli);
char* bitki_yenildi_gorunum(struct CANLI* canli);
void bitki_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum);
struct BITKI* bitki_olustur(int deger);
void bitki_sil(struct BITKI* bitki);

#endif