#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "RASTGELE.h"



struct KIMLIKNO
{
    int diziUzunluk;
    int *arrtcKimlikNo;
    char *chrtcKimlikNo;
    int *kontroltc;
    int gecerliTcSayac;
    int gecersizTcSayac;
    struct RASTGELE* rastgele;
    char* (*tcKimlikNoGetir)(struct KIMLIKNO*);
    void (*kimlikNoKontrolEt)(struct KIMLIKNO*);
    void (*KimlikNoYoket)(struct KIMLIKNO*);
};
typedef struct KIMLIKNO* KimlikNo;
typedef enum{false,true}bool;

KimlikNo KimlikNoOlustur();
char* _tcKimlikNoGetir(const KimlikNo);
void  _kimlikNoKontrolEt(const KimlikNo); 
void  _KimlikNoYoket(KimlikNo );

#endif