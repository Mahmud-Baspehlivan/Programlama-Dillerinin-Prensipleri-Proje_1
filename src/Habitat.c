/* Habitat.c */
#include "Habitat.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void habitat_baslat(struct HABITAT *habitat)
{
    habitat->satirSayisi = 0;
    habitat->sutunSayisi = 0;
    habitat->canlilar = NULL;
}

void habitat_doldur(struct HABITAT *habitat, char *dosyaAdi)
{
    FILE *fp = fopen(dosyaAdi, "r");
    if (fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    int satirSayisi = 0, sutunSayisi = 0;
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp); // İlk satırı oku (sutun sayısını içerir)
    char *token = strtok(buffer, " ");
    while (token != NULL)
    {
        sutunSayisi++;
        token = strtok(NULL, " ");
    }

    rewind(fp); // Dosya işaretçisini başa al

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        satirSayisi++;
    }

    rewind(fp); // Dosya işaretçisini başa al

    habitat->satirSayisi = satirSayisi;
    habitat->sutunSayisi = sutunSayisi;
    habitat->canlilar = malloc(satirSayisi * sizeof(struct CANLI **));
    for (int i = 0; i < satirSayisi; i++)
    {
        habitat->canlilar[i] = malloc(sutunSayisi * sizeof(struct CANLI *));
    }

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        int j = 0;
        token = strtok(buffer, " ");
        while (token != NULL)
        {
            int deger = atoi(token);
            if (deger >= 1 && deger <= 9)
            {
                habitat->canlilar[i][j] = (struct CANLI *)bitki_olustur(deger);
            }
            else if (deger >= 10 && deger <= 20)
            {
                habitat->canlilar[i][j] = (struct CANLI *)bocek_olustur(deger);
            }
            else if (deger >= 21 && deger <= 50)
            {
                habitat->canlilar[i][j] = (struct CANLI *)sinek_olustur(deger);
            }
            else if (deger >= 51 && deger <= 99)
            {
                habitat->canlilar[i][j] = (struct CANLI *)pire_olustur(deger);
            }
            j++;
            token = strtok(NULL, " ");
        }
        i++;
    }

    fclose(fp);
}

void habitat_yazdir(struct HABITAT *habitat)
{
    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        for (int j = 0; j < habitat->sutunSayisi; j++)
        {
            printf("%c ", habitat->canlilar[i][j]->gorunum);
        }
        printf("\n");
    }
}

void habitat_surec(struct HABITAT* habitat) {
    int i = 0, j = 0;
    while (i < habitat->satirSayisi && j < habitat->sutunSayisi) {
        struct CANLI* canli1 = habitat->canlilar[i][j];
        struct CANLI* canli2 = NULL;
        if (j + 1 < habitat->sutunSayisi) {
            canli2 = habitat->canlilar[i][j + 1];
        } else if (i + 1 < habitat->satirSayisi) {
            i++;
            j = 0;
            canli2 = habitat->canlilar[i][j];
        }

        if (canli2 != NULL) {
            void (*hayatta_kal1)(struct CANLI*) = canli1->hayatta_kal;
            void (*hayatta_kal2)(struct CANLI*) = canli2->hayatta_kal;
            void (*gorunum_degistir1)(struct CANLI*, GORUNUM_FONKSIYONU) = canli1->gorunum_degistir;
            void (*gorunum_degistir2)(struct CANLI*, GORUNUM_FONKSIYONU) = canli2->gorunum_degistir;

            hayatta_kal1(canli2);
            hayatta_kal2(canli1);

            if (canli1->deger == 0) {
                gorunum_degistir1(canli1, bitki_gorunum);
            }
            if (canli2->deger == 0) {
                gorunum_degistir2(canli2, bitki_gorunum);
            }

            if (canli1->gorunum == 'C') {
                if (canli2->gorunum == 'B') {
                    gorunum_degistir2(canli2, bitki_gorunum);
                } else if (canli2->gorunum == 'S') {
                    gorunum_degistir1(canli1, bocek_gorunum);
                }
            } else if (canli1->gorunum == 'B') {
                if (canli2->gorunum == 'P') {
                    // Bitki, Pire'yi yemez
                } else if (canli2->gorunum == 'S') {
                    gorunum_degistir2(canli2, sinek_gorunum);
                }
            } else if (canli1->gorunum == 'P') {
                if (canli2->gorunum == 'B') {
                    gorunum_degistir1(canli2, bitki_gorunum);
                } else if (canli2->gorunum == 'C') {
                    gorunum_degistir2(canli2, bocek_gorunum);
                }
            } else if (canli1->gorunum == 'S') {
                if (canli2->gorunum == 'B') {
                    gorunum_degistir1(canli2, bitki_gorunum);
                } else if (canli2->gorunum == 'C') {
                    gorunum_degistir1(canli1, sinek_gorunum);
                }
            }

            if (canli1->deger > canli2->deger) {
                gorunum_degistir2(canli2, bitki_gorunum);
            } else if (canli1->deger < canli2->deger) {
                gorunum_degistir1(canli1, bitki_gorunum);
            } else {
                int satirFarki1 = abs(i - habitat->satirSayisi);
                int satirFarki2 = abs(i - habitat->satirSayisi);
                int sutunFarki1 = abs(j - habitat->sutunSayisi);
                int sutunFarki2 = abs((j + 1) - habitat->sutunSayisi);
                int mesafe1 = satirFarki1 + sutunFarki1;
                int mesafe2 = satirFarki2 + sutunFarki2;
                if (mesafe1 < mesafe2) {
                    gorunum_degistir2(canli2, bitki_gorunum);
                } else {
                    gorunum_degistir1(canli1, bitki_gorunum);
                }
            }
        }

        habitat_yazdir(habitat);
        j++;
    }
}
void habitat_sonucYazdir(struct HABITAT *habitat)
{
    // Buraya sonuc yazdirma kodunu yazabilirsiniz
}