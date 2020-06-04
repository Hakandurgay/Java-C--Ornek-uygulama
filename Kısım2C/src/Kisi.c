#include "Kisi.h"
#include "Telefon.h"
#include "KimlikNo.h"
Kisi KisiOlustur()
{
    Kisi this=(Kisi)malloc(sizeof(struct KISI));
    this->kimlikNo=KimlikNoOlustur();
    this->telefon=telefonOlustur();
    this->rastgele=RastgeleOlustur();
    this->kisiUret=&_kisiUret;
    this->KisiYoket=&_KisiYoket;
	return this;
}
int _dosyaSatirSayisiBul(const Kisi this) //isimler dosyasının satır sayısı bulunuyor
{
		FILE *dosya;
		this->satirSayisi=1;
		char oku;

		dosya=fopen("isimler.txt", "r");
		while(!feof(dosya)){
			oku=getc(dosya);
			if(oku=='\n'){
				this->satirSayisi++;
			}
		}
		fclose(dosya);
		return this->satirSayisi;
}

char* _rastgeleAdSoyadGetir(const Kisi this)
{
    int rastgeleSatir=0;
    int sayac=0;
int dosyaDegerSayisi=_dosyaSatirSayisiBul(this); //isimler dosyasında kaç adet satır olduğu bulunuyor ve rastgele gelen değerlerin bu satır sayısı aralığında olması sağlanıyor
    char* isim="";
    while(rastgeleSatir==0)
        rastgeleSatir=this->rastgele->randomDegerGetir(this->rastgele)%dosyaDegerSayisi;
    FILE * fp;
    char * line = NULL;
    size_t len = 0;

    fp = fopen("isimler.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((getline(&line, &len, fp)) != -1) {
        sayac++;
        if(sayac==rastgeleSatir)
        {
            strtok(line,"\n");
            this->adSoyad=line;
            break;
        }
    }
    fclose(fp);
    return this->adSoyad;
}
void _kisileriDosyayaYaz(const Kisi this)
{

    FILE *fp=fopen("Kisiler.txt","a");

    fprintf(fp,"%s %s %d %s\n",this->tcNo,this->adSoyad,this->yas,this->kisitelefonVeImei);
fclose(fp);
}

void _kisiUret(const Kisi this)
{
    this->tcNo=this->kimlikNo->tcKimlikNoGetir(this->kimlikNo);
    this->kisitelefonVeImei=this->telefon->telefonVeImeiGetir(this->telefon);
    this->yas=this->rastgele->randomDegerGetir(this->rastgele)%100;
    this->adSoyad=_rastgeleAdSoyadGetir(this);
    _kisileriDosyayaYaz(this);
}
void _KisiYoket(Kisi this)
{
    if(this==NULL)return;
    this->kimlikNo->KimlikNoYoket(this->kimlikNo);
    this->telefon->TelefonYoket(this->telefon);
    this->rastgele->RastgeleYoket(this->rastgele);
    free(this);


}
