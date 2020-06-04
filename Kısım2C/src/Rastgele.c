#include "RASTGELE.h"

Rastgele RastgeleOlustur()
{
    Rastgele this;
    this = (Rastgele)malloc(sizeof(struct RASTGELE));
    this->last=0;
    this->sayac = 0;
    this->deger = 32749;
    time_t currenTime;
    time(&currenTime);
    struct tm *mytime = localtime(&currenTime);
    this->last=mytime->tm_sec;
    this->randomDegerGetir=&_randomDegerGetir;
    this->RastgeleYoket=&_RastgeleYoket;
    return this;
}

int _randomDegerGetir(const Rastgele this)
{
    this->sayac++;
    if(this->sayac==this->deger)
        this->deger=this->deger*2;
    this->last=(this->last*32719+3)%this->deger;
    return this->last;
}

void _RastgeleYoket(Rastgele this)
{
    if(this==NULL)
        return;
    free(this);

}