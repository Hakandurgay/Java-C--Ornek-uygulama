#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur()
{
    RastgeleKisi this=(RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
    this->kisi=KisiOlustur();
    this->imeiKontrol=ImeiNoOlustur();
    this->tcKontrol=KimlikNoOlustur();
    this->islemYap=&_islemYap;
    this->RastgeleKisiYoket=&_RastgeleKisiYoket;
return this;
}

void _yeniKisiUret(const RastgeleKisi this)
{
    int kisiSayisi;
    printf("Kac Tane Kisi Uretmek Istiyorsunuz?");
    scanf("%d",&kisiSayisi);
        for(int i=0; i<kisiSayisi;i++)
            this->kisi->kisiUret(this->kisi);
}
void _dosyaKontrolEt(const RastgeleKisi this)
{
    this->imeiKontrol->imeiNoKontrol(this->imeiKontrol);
    this->tcKontrol->kimlikNoKontrolEt(this->tcKontrol);
}
void _islemYap(const RastgeleKisi this)   //public
{
    int secim;
    do{
       printf("1- Rastgele Kisi Uret\n");
        printf("2- Uretilmis Dosya Kontrol Et\n");
        printf("3- Kaydin tamamlanmasi ve cikis icin 3'e basin\n");
        scanf("%d",&secim);

       if(secim==1)
           _yeniKisiUret(this);
        if(secim==2)
            _dosyaKontrolEt(this);

    }while(secim!=3);
}
void _RastgeleKisiYoket(RastgeleKisi this)
{
    if(this==NULL)return;
    this->kisi->KisiYoket(this->kisi);
    this->imeiKontrol->ImeiNoYoket(this->imeiKontrol);
    this->tcKontrol->KimlikNoYoket(this->tcKontrol);
    free(this);
}
