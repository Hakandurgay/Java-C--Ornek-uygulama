#ifndef IMEINO_H
#define IMEINO_H

#include "Rastgele.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

struct IMEINO{
    int diziUzunluk;
    int *imei;
    int *carpimVeToplamlar;
    int *imeiKontrol;
    int gecerliImeiSayac;
    int gecersizImeiSayac;
    int toplam;
    struct RASTGELE* rastgele;
    int* (*imeiNoGetir)(struct IMEINO*);  //pub
    void (*imeiNoKontrol)(struct IMEINO*); //pub
    void (*ImeiNoYoket)(struct IMEINO*);//pub
};
typedef struct IMEINO* ImeiNo;


ImeiNo ImeiNoOlustur();
int* _imeiNoGetir(const ImeiNo);
void _imeiNoKontrol(const ImeiNo );
void _ImeiNoYoket(ImeiNo );


#endif