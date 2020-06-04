#include "ImeiNo.h"

ImeiNo ImeiNoOlustur()
{
    ImeiNo this=(ImeiNo)malloc(sizeof(struct IMEINO));
    this->diziUzunluk=15;
    this->imei=(int*)malloc(sizeof(int)*this->diziUzunluk);    //diziler heap bölgesinde oluşturuluyor
    this->carpimVeToplamlar=(int*)malloc(sizeof(int)*this->diziUzunluk);
    this->imeiKontrol=(int*)malloc(sizeof(int)*this->diziUzunluk);
    this->rastgele=RastgeleOlustur();
    this->imeiNoGetir=&_imeiNoGetir;
    this->imeiNoKontrol=&_imeiNoKontrol;
    this->ImeiNoYoket=&_ImeiNoYoket;
    this->toplam=0;
    this->gecerliImeiSayac=0;
    this->gecersizImeiSayac=0;
return this;
}
void _imeiUret(const ImeiNo this) //private
{
    for (int i = 0; i < 14; ++i) {
        this->imei[i]=this->rastgele->randomDegerGetir(this->rastgele)%10;
        this->carpimVeToplamlar[i]=this->imei[i];
    }
    for (int i = 1; i < 14; i+=2)
    {
        this->carpimVeToplamlar[i]=this->carpimVeToplamlar[i]*2;    //tek basakmaklar ikiyle çarpılıyor ve sayı ondan büyükse rakamlar toplanıyor
        int birlerBasamagi=this->carpimVeToplamlar[i]%10;
        int onlarBasamagi=this->carpimVeToplamlar[i]/10;
        this->carpimVeToplamlar[i]=birlerBasamagi+onlarBasamagi;
    }
    for (int i = 0; i < 14; i++)
    {
        this->toplam+=this->carpimVeToplamlar[i];     //çarpılan sayılar toplanıyor
    }
    this-> toplam=( this->toplam*9)%10;  //15. basamak belirleniyor
    this->imei[14]= this->toplam;
    this->toplam=0;
}
void imeiKuralKontrolEt(const ImeiNo this) //private
{
   int toplam=0;
    for (int i = 1; i < 14; i+=2)
    {
        this->imeiKontrol[i]=this->imeiKontrol[i]*2;
        int birlerBasamagi=this->imeiKontrol[i]%10;
        int onlarBasamagi=this->imeiKontrol[i]/10;
        this->imeiKontrol[i]=birlerBasamagi+onlarBasamagi;
    }
    for (int i = 0; i < 15; i++)
    {
        toplam+=this->imeiKontrol[i];
    }
    if(toplam%10==0)
        this->gecerliImeiSayac++;

    else
        this->gecersizImeiSayac++;
}
void dosyaOkuBasamakSayisiBul(const ImeiNo this) //private
{                                    //bu fonksiyonda dosya okunuyor ve imei numarasının basamak sayısı kontrol ediliyor. Ardından check digit kontrolü için diger fonksiyon cagriliyor
    int bayrak=0;
    int index=0;
    FILE * fp = fopen("kisiler.txt", "r");
    char c;
    int kelimeSayac = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if(c == ' ' || c == '\n' )
        {
            if((kelimeSayac-5)%6==0 &&bayrak==1)
            {
                imeiKuralKontrolEt(this);
            }
            else if((kelimeSayac-5)%6==0 &&bayrak==0)
                this->gecersizImeiSayac++;
            kelimeSayac++;
            index=0;
        }
        else if(c!='(' && c!=')')
        {
            if((kelimeSayac-5)%6==0)
            {
                if(index<=14)
                {
                    this->imeiKontrol[index]=c-'0';
                    index++;
                    bayrak=1;
                }
                else
                {
                    bayrak=0;
                }
            }
        }
    }
    fclose(fp);
}
int* _imeiNoGetir(const ImeiNo this) //public
{
    _imeiUret(this);
    return this->imei;
}
void _imeiNoKontrol(const ImeiNo this) //public fonksiyon
{
	this->gecerliImeiSayac=0;
	this->gecersizImeiSayac=0;
    dosyaOkuBasamakSayisiBul(this);
    printf("Gecerli Imei Numarasi Sayisi: %d\n",this->gecerliImeiSayac);
    printf("Gecersiz Imei Numarasi Sayisi: %d\n",this->gecersizImeiSayac);
}
void _ImeiNoYoket(ImeiNo this)
{
    if(this==NULL)return;
    this->rastgele->RastgeleYoket(this->rastgele);
    free(this->imei);
    free(this->carpimVeToplamlar);
    free(this->imeiKontrol);
    free(this);

}
