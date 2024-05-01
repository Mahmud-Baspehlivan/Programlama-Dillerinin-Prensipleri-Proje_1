/* Bocek.h */
#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
    struct CANLI canli;
};

char* bocek_gorunum(struct CANLI* canli);
void bocek_gorunum_degistir(struct CANLI* canli, GORUNUM_FONKSIYONU yeni_gorunum);
struct BOCEK* bocek_olustur(int deger);
void bocek_sil(struct BOCEK* bocek);

#endif