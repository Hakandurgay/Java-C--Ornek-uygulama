/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
#ifndef KISI_H
#define KISI_H
struct KISI
{
    char* kisitelefonVeImei;
    char* tcNo;
    char* adSoyad;
    int yas;
    int satirSayisi;
    struct RASTGELE* rastgele;
    struct KIMLIKNO* kimlikNo;
    struct TELEFON* telefon;
   
    void (*kisiUret)(struct KISI*);
    void (*KisiYoket)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi KisiOlustur();
void _kisiUret(const Kisi );
void _KisiYoket(Kisi );



#endif