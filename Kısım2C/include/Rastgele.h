/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
#ifndef RASTGELE_H 
#define RASTGELE_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
struct RASTGELE
{
    int last;
    int sayac;
    int deger;
    int (*randomDegerGetir)(struct RASTGELE*);
    void (*RastgeleYoket)(struct RASTGELE*);
};
typedef struct RASTGELE* Rastgele;


Rastgele RastgeleOlustur();
int _randomDegerGetir(const Rastgele);
void _RastgeleYoket(Rastgele );
#endif