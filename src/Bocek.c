/* Bocek.c */
#include "Bocek.h"
#include "Canli.h"
#include <stdio.h>
#include <stdlib.h>

char* bocek_gorunum(struct CANLI* canli) {
    return "C";
}


struct BOCEK* bocek_olustur(int deger) {
    struct BOCEK* bocek = malloc(sizeof(struct BOCEK));
    bocek->canli = *canli_olustur(deger, bocek_gorunum);
    return bocek;
}

void bocek_sil(struct BOCEK* bocek) {
    canli_sil(&bocek->canli);
    free(bocek);
}