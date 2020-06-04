#include "Rastgele.h"
#include "ImeiNo.h"
#include "Telefon.h"
Telefon telefonOlustur()
{
    Telefon this=(Telefon)malloc(sizeof(struct TELEFON));
    this->telefonDiziUzunlugu=11;
    this->telefonVeImeiDiziUzunlugu=29;
    this->telefon=(int*)malloc(sizeof(int)*this->telefonDiziUzunlugu);
    this->telefonVeImei=(char*)malloc(sizeof(char)*this->telefonVeImeiDiziUzunlugu);

    this->rastgele=RastgeleOlustur();
    this->imeino=ImeiNoOlustur();
    this->telefonVeImeiGetir=&_telefonVeImeiGetir;
    this->TelefonYoket=&_TelefonYoket;
    return this;
}
void _telefonNoUret(const Telefon this)  
{
    this->telefon[0]=0;
    this->telefon[1]=5;
    while(1)
    {
        this->telefon[2]=this->rastgele->randomDegerGetir(this->rastgele)%10;
        if(this->telefon[2]==0 || this->telefon[2]==3 || this->telefon[2]==4 || this->telefon[2]==5|| this->telefon[2]==6)
            break;
    }
    while(1)
    {
        this->telefon[3]=this->rastgele->randomDegerGetir(this->rastgele)%10;
        if(this->telefon[2]==0)
        {
            if(this->telefon[3]==1 || this->telefon[3]==5 || this->telefon[3]==6 || this->telefon[3]==7)
                break;
        }
        else if(this->telefon[2]==3)
        {
            break;
        }
        else if(this->telefon[2]==4)
        {
            break;
        }
        else if(this->telefon[2]==5)
        {
            if(this->telefon[3]==2 || this->telefon[3]==3 || this->telefon[3]==4 || this->telefon[3]==5||this->telefon[3]==9)
                break;
        }
        else if(this->telefon[2]==6)
        {
            if(this->telefon[3]==1)
                break;
        }
    }
    for(int i=4; i<11;i++)
    {
        this->telefon[i]=this->rastgele->randomDegerGetir(this->rastgele)%10;
    }
}
char* _imeiveTelefonBirlestir(const Telefon this)   //bu fonksiyonda imeino üretiliyor ve telefon numarasıyla aynı char* dizisine yazılıyor
{
    int n = 0;    
    this->imeino->imeiNoGetir(this->imeino);
    _telefonNoUret(this);
    for (int i = 0; i < 26; i++) {
        if(i<11)
            n += sprintf (&this->telefonVeImei[n], "%d", this->telefon[i]);
        else if(i==11)
            n += sprintf (&this->telefonVeImei[n], " (%d",this->imeino->imei[i-11]);
        else if(i>11&&i<25)
        {
            n += sprintf (&this->telefonVeImei[n], "%d", this->imeino->imei[i-11]);
        }
        else if (i==25)
        {
            n += sprintf (&this->telefonVeImei[n], "%d)", this->imeino->imei[i-11]);

        }
    }
    return this->telefonVeImei;

}
char* _telefonVeImeiGetir(const Telefon this)
{
    _imeiveTelefonBirlestir(this);
    return this->telefonVeImei;
}
void _TelefonYoket(Telefon this)
{
    if(this==NULL)return;
    this->rastgele->RastgeleYoket(this->rastgele);
    this->imeino->ImeiNoYoket(this->imeino);
    free(this->telefon);
    free(this->telefonVeImei);
    free(this);

}