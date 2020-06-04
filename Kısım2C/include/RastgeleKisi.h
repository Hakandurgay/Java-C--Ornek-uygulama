/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "Kisi.h"
#include "KimlikNo.h"
#include "ImeiNo.h"
#include "stdio.h"
#include "stdlib.h"
struct RASTGELEKISI{

    struct KISI* kisi;
    struct IMEINO* imeiKontrol;
    struct KIMLIKNO* tcKontrol;
    void (*islemYap)(struct RASTGELEKISI*);
    void (*RastgeleKisiYoket)(struct RASTGELEKISI*);

};
typedef struct RASTGELEKISI* RastgeleKisi;

RastgeleKisi RastgeleKisiOlustur();

void _islemYap(const RastgeleKisi );
void _RastgeleKisiYoket(RastgeleKisi);




#endif