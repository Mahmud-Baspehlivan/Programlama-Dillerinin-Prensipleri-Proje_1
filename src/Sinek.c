/* Sinek.c */
#include "Sinek.h"
#include "Bocek.h"
#include <stdio.h>
#include <stdlib.h>

char* sinek_gorunum(struct CANLI* canli) {
    return "S";
}
struct SINEK* sinek_olustur(int deger) {
    struct SINEK* sinek = malloc(sizeof(struct SINEK));
    sinek->bocek.canli = *canli_olustur(deger, sinek_gorunum);
    return sinek;
}

void sinek_sil(struct SINEK* sinek) {
    canli_sil(&sinek->bocek.canli);
    free(sinek);
}