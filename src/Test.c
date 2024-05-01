/* Test.c */
#include "Habitat.h"
#include <stdio.h>

int main() {
    struct HABITAT habitat;

    habitat_baslat(&habitat);
    habitat_doldur(&habitat, "./doc/Veri.txt");

    printf("Baslangic durumu:\n");
    //habitat_yazdir(&habitat);

    printf("\nSurec baslatiliyor... (Herhangi bir tusa basin)\n");
    getchar();

    habitat_surec(&habitat);

    return 0;
}