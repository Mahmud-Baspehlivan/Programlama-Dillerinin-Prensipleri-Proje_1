/* Canli.h */
#ifndef CANLI_H
#define CANLI_H

struct CANLI;

typedef char* (*GORUNUM_FONKSIYONU)(struct CANLI*);

struct CANLI {
    int deger;
    char gorunum;
    void (*hayatta_kal)(struct CANLI*);
    void (*gorunum_degistir)(struct CANLI*, GORUNUM_FONKSIYONU);
};

struct CANLI* canli_olustur(int deger, GORUNUM_FONKSIYONU gorunum, void (*hayatta_kal)(struct CANLI*), void (*gorunum_degistir)(struct CANLI*, GORUNUM_FONKSIYONU));
void canli_sil(struct CANLI* canli);

#endif