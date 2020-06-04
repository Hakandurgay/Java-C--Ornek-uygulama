/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
#include "KIMLIKNO.h"


KimlikNo KimlikNoOlustur()
{

    KimlikNo this=(KimlikNo)malloc(sizeof(struct KIMLIKNO));
    this->diziUzunluk=11;
    this->arrtcKimlikNo=(int*)malloc(sizeof(int)*this->diziUzunluk);
    this->chrtcKimlikNo=(char*)malloc(sizeof(char)*this->diziUzunluk);
    this->kontroltc=(int*)malloc(sizeof(int)*this->diziUzunluk);
    this->rastgele=RastgeleOlustur(); 
    this->tcKimlikNoGetir=&_tcKimlikNoGetir;
    this->kimlikNoKontrolEt=&_kimlikNoKontrolEt;
    this->KimlikNoYoket=&_KimlikNoYoket;
    this->gecerliTcSayac=0;
    this->gecersizTcSayac=0;
    return this;
}
void _tcKimlikNoUret(const KimlikNo this) //private
{
    int birinciBasamak= this->rastgele->randomDegerGetir(this->rastgele)%10;
    if(birinciBasamak==0)
        birinciBasamak++;
    this->arrtcKimlikNo[0]=birinciBasamak;

    for (int i = 1; i <9; i++)
        this->arrtcKimlikNo[i]=this->rastgele->randomDegerGetir(this->rastgele)%10;
    int birinciKural_ciftBasamaklar=0; ////1-3-5-7-9 basamak toplamanın 7 ile çarpımı ile 2-4-6-8. basamağın 9 ile çarpımının 10'a bölümünden kalan rakam 10. basamaktaki ile aynı olmalı.

    for (int i = 0; i < 9; i+=2)
    {
        birinciKural_ciftBasamaklar+=this->arrtcKimlikNo[i];
    }
    int birinciKural_tekBasamaklar=0;
    for (int i = 1; i < 8; i+=2)
    {
        birinciKural_tekBasamaklar+=this->arrtcKimlikNo[i];
    }
    int onuncuBasamaktakiSayi = (birinciKural_ciftBasamaklar * 7-birinciKural_tekBasamaklar) % 10;

    this->arrtcKimlikNo[9]=onuncuBasamaktakiSayi;
    int  ikinciKural=0; //ilk on basamaktaki sayiların toplamının 10'a bölümünden kalan sayı 11. basamaktakine eşittir.

    for(int i=0;i<10;i++) //ilk on basamak toplanıyor
        ikinciKural+= this->arrtcKimlikNo[i];

    ikinciKural=ikinciKural%10;
    this->arrtcKimlikNo[10]=ikinciKural;

}
char* _kimlikNotoString(const KimlikNo this)// private
{    int n = 0;

    _tcKimlikNoUret(this);
    for (int i = 0; i < 11; i++) {

        n += sprintf (&this->chrtcKimlikNo[n], "%d", this->arrtcKimlikNo[i]);
    }
    return this->chrtcKimlikNo;
}

int _tcKontrolEt(const KimlikNo this) //private  //tc numarası kuralları kontrol ediliyor
{
	
    int birinciKontrol_tekToplam=0;
    int birinciKontrol_ciftToplam=0;
    int birinciKontrol=0;    //1,3,5,7,9. basamağın 7 ile çarpımı ile 2,4,6,8. basamağın 9 ile çarpımının 10'a bölümünden kalanının
    int ikinciKontrol=0;    //ilk basamağın sıfır olup olmadığı kontrol ediliyor
    int ucuncuKontrol=0;   //ilk on basamağın toplamının mod değerinin, 11. basamağa eşit olup olmadığı kontrol ediliyor

    for (int i=0;i<9;i+=2) //basamak değerleri toplanıyor
        birinciKontrol_tekToplam +=this->kontroltc[i];
    for (int i=1;i<8;i+=2)
        birinciKontrol_ciftToplam += this->kontroltc[i];
    birinciKontrol=((birinciKontrol_ciftToplam*9)+(birinciKontrol_tekToplam*7))%10;

    ikinciKontrol=this->kontroltc[0];
    for(int i=0;i<10;i++) //ilk on basamak toplanıyor
        ucuncuKontrol+= this->kontroltc[i];
    ucuncuKontrol=ucuncuKontrol%10;
        if(birinciKontrol==this->kontroltc[9] && ikinciKontrol!=0  && ucuncuKontrol==this->kontroltc[10])
        return 1;
    else
        return 0;
}
void dosyaOkuVeBasamakSay(const KimlikNo this) //private  //dosya okuma ve tc basamak saysısı kontrol işlemleri burada yapılıyor
{                        
    bool bayrak=false;
    int index=0;
    FILE * fp = fopen("kisiler.txt", "r");
    char c;
    int kelimeSayac = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if(c == ' ' || c == '\n' )
        {
            if(kelimeSayac % 6 == 0 &&bayrak==true )
            {
                if( _tcKontrolEt(this)==1)
                {
                    this->gecerliTcSayac++;
                }
                else if(_tcKontrolEt(this)==0)
                 {
                    this->gecersizTcSayac++;
                 }
            }
            else if(kelimeSayac % 6 == 0 &&bayrak==false)
                this->gecersizTcSayac++;
            kelimeSayac++;
            index=0;
        }
        else
        {
            if(kelimeSayac % 6 == 0)
            {
                if(index<=10)
                {
                    this->kontroltc[index]=c-'0';
                    index++;
                    bayrak=true;
                }
                else
                {
                    bayrak=false;
                }
            }
        }
    }
    fclose(fp);
}

char* _tcKimlikNoGetir(const KimlikNo this) //public 
{
    _kimlikNotoString(this);
    return this->chrtcKimlikNo;
}
void _kimlikNoKontrolEt(const KimlikNo this) //public
{
	this->gecerliTcSayac=0;
	this->gecersizTcSayac=0;
    dosyaOkuVeBasamakSay(this);
    printf("Gecerli Tc Kimlik Numarasi Sayisi: %d\n",this->gecerliTcSayac);
    printf("Gecersiz Tc Kimlik Numarasi Sayisi: %d\n",this->gecersizTcSayac);
}

void _KimlikNoYoket(KimlikNo this)
{
    if (this == NULL)return;
    this->rastgele->RastgeleYoket(this->rastgele);
    free(this->arrtcKimlikNo);
    free(this->kontroltc);
    free(this->chrtcKimlikNo);
    free(this);


}

