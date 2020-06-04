/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
#ifndef TELEFON_H
#define TELEFON_H

#include "Rastgele.h"
#include "ImeiNo.h"

struct TELEFON
{
    int telefonDiziUzunlugu;
    int telefonVeImeiDiziUzunlugu;
    int *telefon;
    char *telefonVeImei;
    struct RASTGELE* rastgele;
    struct IMEINO* imeino;
    char* (*telefonVeImeiGetir)(struct TELEFON*);
    void (*TelefonYoket)(struct TELEFON*);
};

typedef struct TELEFON* Telefon;

Telefon telefonOlustur();
char* _telefonVeImeiGetir(const Telefon );
void _TelefonYoket(Telefon );


#endif