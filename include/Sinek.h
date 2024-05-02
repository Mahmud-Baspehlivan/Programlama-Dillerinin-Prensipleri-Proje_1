/* Sinek.h */
#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
    struct BOCEK bocek;
};

char* sinek_gorunum(struct CANLI* canli);
struct SINEK* sinek_olustur(int deger);
void sinek_sil(struct SINEK* sinek);

#endif