/* Bitki.h */
#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    struct CANLI canli;
};

char* bitki_gorunum(struct CANLI* canli);
char* bitki_yenildi_gorunum(struct CANLI* canli);
struct BITKI* bitki_olustur(int deger);
void bitki_sil(struct BITKI* bitki);

#endif