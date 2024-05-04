/* Habitat.h */
#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"

struct HABITAT {
    struct CANLI*** canlilar;
    int satirSayisi;
    int sutunSayisi;
};

void habitat_baslat(struct HABITAT* habitat);
void habitat_doldur(struct HABITAT* habitat, char* dosyaAdi);
void habitat_yazdir(struct HABITAT* habitat);
void habitat_surec(struct HABITAT* habitat);
void habitat_sonuc(struct HABITAT* habitat);
#endif