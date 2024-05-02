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
    char buffer[100000];
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
    int i = 0, j = 0, k = 0, z = 0;
    struct CANLI* kazanan = NULL; // Kazananı temsil etmek için bir işaretçi
    struct CANLI* canli1 = NULL;
    struct CANLI* canli2 = NULL;
    while (i < habitat->satirSayisi && j < habitat->sutunSayisi) {
        canli1 = habitat->canlilar[k][z];
        if (j + 1 < habitat->sutunSayisi) {
            canli2 = habitat->canlilar[i][j + 1];
        } else if (i + 1 < habitat->satirSayisi) {
            i++;
            j = 0;
            canli2 = habitat->canlilar[i][j];
        }
        
        if (canli2 != NULL) {
            
            if (canli1->gorunum == canli2->gorunum) {
                // Karşılaşan karakterler aynı ise, veri.txt'deki sayısal değeri büyük olan kazanır
                // Eğer sayısal değerler eşitse, matrisin son elemanına olan uzaklıklara bakılarak daha yakın olan ölecek
                int canli1_sayi = canli1->deger;
                int canli2_sayi = canli2->deger;

                if (canli1_sayi > canli2_sayi) {
                    canli2->gorunum = 'X';
                    j++;
                } else if (canli1_sayi < canli2_sayi) {
                    canli1->gorunum = 'X';
                    if(i == k){
                        j++;
                        z=j;
                        canli1 = habitat->canlilar[k][z];
                    }else if(j==0){
                        k=i;
                        z=j;
                        canli1 = habitat->canlilar[k][z];
                    } else{
                        k=i;
                        z=++j;
                        canli1 = habitat->canlilar[k][z];
                    }   
                } else {
                    // Eğer sayısal değerler eşitse, matrisin son elemanına olan uzaklıklara bakılarak daha yakın olan ölecek
                    int son_satir = habitat->satirSayisi - 1;
                    int son_sutun = habitat->sutunSayisi - 1;
                    int uzaklik_canli1 = abs(k - son_satir) + abs(z - son_sutun);
                    int uzaklik_canli2 = abs(i - son_satir) + abs(j - son_sutun);

                    if (uzaklik_canli1 < uzaklik_canli2) {
                        canli1->gorunum = 'X';
                        if(i == k){
                            j++;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        }else if(j==0){
                            k=i;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        } else{
                            k=i;
                            z=++j;
                            canli1 = habitat->canlilar[k][z];
                        }
                    } else if (uzaklik_canli1 > uzaklik_canli2) {
                        canli2->gorunum = 'X';
                        j++;
                    } else {
                        // Eğer uzaklıklar da eşitse, yatay konumlarına bakarak hangisi daha aşağıda ise onun ölmesini sağla
                        if (i > k) {
                            canli1->gorunum = 'X';
                            if(i == k){
                                j++;
                                z=j;
                                canli1 = habitat->canlilar[k][z];
                            }else if(j==0){
                                k=i;
                                z=j;
                                canli1 = habitat->canlilar[k][z];
                            } else{
                                k=i;
                                z=++j;
                                canli1 = habitat->canlilar[k][z];
                            }
                        } else {
                            canli2->gorunum = 'X';
                            j++;
                        }
                    }
                }
            } else{
                    
                if (canli1->gorunum == 'C') {
                    if (canli2->gorunum == 'B' || canli2->gorunum == 'P') {
                        canli2->gorunum = 'X';
                        j++;
                    } else if (canli2->gorunum == 'S') {
                        canli1->gorunum = 'X';
                        
                        if(i == k){
                            j++;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        }else if(j==0){
                            k=i;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        } else{
                            k=i;
                            z=++j;
                            canli1 = habitat->canlilar[k][z];
                        }
                    }
                } else if (canli1->gorunum == 'B') {
                    if (canli2->gorunum == 'P' || canli2->gorunum == 'S') {
                        canli2->gorunum = 'X';
                        j++;
                    } else if (canli2->gorunum == 'C') {
                        canli1->gorunum = 'X';
                        if(i == k){
                            j++;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        }else if(j==0){
                            k=i;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        } else{
                            k=i;
                            z=++j;
                            canli1 = habitat->canlilar[k][z];
                        }
                    }
                } else if (canli1->gorunum == 'P') {
                    if (canli2->gorunum == 'C' || canli2->gorunum == 'B' || canli2->gorunum == 'S') {
                        canli1->gorunum = 'X';
                        if(i == k){
                            j++;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        }else if(j==0){
                            k=i;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        } else{
                            k=i;
                            z=++j;
                            canli1 = habitat->canlilar[k][z];
                        }
                    }
                } else if (canli1->gorunum == 'S') {
                    if (canli2->gorunum == 'B') {
                        canli1->gorunum = 'X';
                        if(i == k){
                            j++;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        }else if(j==0){
                            k=i;
                            z=j;
                            canli1 = habitat->canlilar[k][z];
                        } else{
                            k=i;
                            z=++j;
                            canli1 = habitat->canlilar[k][z];
                        }
                    } else if (canli2->gorunum == 'C' || canli2->gorunum == 'P') {
                        canli2->gorunum = 'X';
                        j++;
                    }
                }
            }
           
        }
        
        if (i >= habitat->satirSayisi - 1 && j >= habitat->sutunSayisi - 1) {
        break;
    }
        
    }
    system(CLEAR_SCREEN);
    habitat_yazdir(habitat);
    if(canli1->gorunum == 'X'){
        kazanan = canli2;
        printf("%s,%c (%i,%i)\n", "Kazanan: ",canli2->gorunum, i, j+1);
    }else if(canli2->gorunum == 'X'){
        kazanan = canli1;
        printf("%s%c (%i,%i)\n", "Kazanan: ",canli1->gorunum, k, z);
    }
    
}
