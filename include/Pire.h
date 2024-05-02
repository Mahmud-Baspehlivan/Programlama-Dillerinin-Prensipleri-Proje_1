/* Pire.h */
#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE {
    struct BOCEK bocek;
};

char* pire_gorunum(struct CANLI* canli);
struct PIRE* pire_olustur(int deger);
void pire_sil(struct PIRE* pire);

#endif