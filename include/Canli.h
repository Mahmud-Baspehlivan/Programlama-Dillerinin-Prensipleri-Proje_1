/* Canli.h */
#ifndef CANLI_H
#define CANLI_H

struct CANLI {
    int deger;
    char gorunum;
};

struct CANLI* canli_olustur(int deger, char* (*gorunum)(struct CANLI*));
void canli_sil(struct CANLI* canli);

#endif