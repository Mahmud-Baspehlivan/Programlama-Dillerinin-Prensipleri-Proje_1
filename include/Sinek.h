/* Sinek.h */
#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
    struct BOCEK bocek;
};

char* sinek_gorunum(struct CANLI* canli);
void sinek_hayatta_kal(struct CANLI* canli);
void sinek_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum);
struct SINEK* sinek_olustur(int deger);
void sinek_sil(struct SINEK* sinek);

#endif