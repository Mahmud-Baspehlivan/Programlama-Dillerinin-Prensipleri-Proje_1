/* Test.c */
#include "Habitat.h"
#include <stdio.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

int main() {
    struct HABITAT habitat;

    habitat_baslat(&habitat);
    habitat_doldur(&habitat, "./doc/Veri.txt");
    system(CLEAR_SCREEN);
    printf("Baslangic durumu:\n");
    habitat_yazdir(&habitat);

    printf("\nSurec baslatiliyor... (Herhangi bir tusa basin)\n");
    getchar();

    habitat_surec(&habitat);
    habitat_sonuc(&habitat);

    return 0;
}