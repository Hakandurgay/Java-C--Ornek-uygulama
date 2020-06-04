/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
package MyPackage;

import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Hakan Durgay
 */
public class  IMEINo{
  private  int [] imei;
  private  int [] carpimVeToplamlar;
  private int [] imeiKontrol;
  private int toplamKontrol;
  private int toplam;
  private int gecerliImeiSayisi;
  private int gecersizImeiSayisi;
  private String kontrolimei;
  private String imeiNo;
  Rastgele rand;
 IMEINo()
 {
        toplam=0;
        gecerliImeiSayisi=0;
        gecersizImeiSayisi=0;
        rand=new Rastgele(10);
        imei=new int[15];
        carpimVeToplamlar=new int[15];
        imeiKontrol=new int[16];
 }
           
    public String imeiNoGetir()
    {
        imeiNo="";
        imeiUret();
        return imeiNo;
    }
    public void imeiNoKontrol() throws FileNotFoundException
    {
        gecersizImeiSayisi=0;
        gecerliImeiSayisi=0;
        imeiKontrolEt();
        System.err.println("Gecerli Imei No Sayisi: "+gecerliImeiSayisi);
                System.err.println("Gecersiz Imei No Sayisi: "+gecersizImeiSayisi);

    }
    private void imeiUret()
    {
        for (int i = 0; i < 14; i++)
        {
            imei[i]=(int)rand.randomDegerGetir();
            carpimVeToplamlar[i]=imei[i];     //ilk hali bozulmaması için başka diziye atılıyor
        }
        for (int i = 1; i < 14; i+=2) 
        {
            carpimVeToplamlar[i]=carpimVeToplamlar[i]*2;    //tek basakmaklar ikiyle çarpılıyor ve sayı ondan büyükse rakamlar toplanıyor
            int birlerBasamagi=carpimVeToplamlar[i]%10;
            int onlarBasamagi=carpimVeToplamlar[i]/10;
            carpimVeToplamlar[i]=birlerBasamagi+onlarBasamagi;
        }
        for (int i = 0; i < 14; i++) 
        {
             toplam+=carpimVeToplamlar[i];     //çarpılan sayılar toplanıyor
        }
        toplam=(toplam*9)%10;  //15. basamak belirleniyor
        imei[14]=toplam;
                toplam=0;
        for (int i = 0; i < 15; i++)
        {   
          imeiNo+=imei[i];  //oluşan imei stringe atılıyor
        }    
    }
    private void imeiKontrolEt() throws FileNotFoundException
    {
        char ch;
        int sayac=0;
        java.io.File dosyaOku = new java.io.File("Kisiler.txt");  //int deger okuma 
          Scanner oku = new Scanner(dosyaOku);

          while (oku.hasNext())
          {      
              if((sayac-5)%6==0) //imeinin bulunduğu sütunlar
              {
                   kontrolimei =oku.next(); //okunan değer stringe atılıyor
                   if(basamakSayisiKontrolEt(kontrolimei))       //imei numarasının basamak sayısı 15 ise check digit kontrolü için diziye atılıyor
                   {
                       for (int i = 1; i < kontrolimei.length(); i++)
                         { 
                                  ch=kontrolimei.charAt(i);  //parantezlerden kurtulmak için döngü birden başlıyor
                                  int rakam = ch - '0'; //chardan inte dönüştürülüyor
                                     imeiKontrol[i-1]=rakam;                                                          
                         }
                       imeiNoDogrulama();
                   }
                   else
                   {
                       gecersizImeiSayisi++;
                   }
              }      
              else
              oku.next();
              sayac++;                        
          }     
          oku.close();
    }
    private boolean basamakSayisiKontrolEt(String imei)
    {
        int basamakSayaci=0;
        for (int i = 0; i < imei.length()-2; i++) 
        {
            basamakSayaci++;
        }
        if(basamakSayaci!=15)
            return false;
        else
            return true;
    }
    private void imeiNoDogrulama()
    {
        toplamKontrol=0;
        toplam=0;
        for (int i = 1; i < 14; i+=2) 
        {
            imeiKontrol[i]=imeiKontrol[i]*2;
            int birlerBasamagi=imeiKontrol[i]%10;
            int onlarBasamagi=imeiKontrol[i]/10;
            imeiKontrol[i]=birlerBasamagi+onlarBasamagi;
        }
        for (int i = 0; i < 15; i++) 
        {
             toplamKontrol+=imeiKontrol[i];  
        }
        if(toplamKontrol%10==0)    
         gecerliImeiSayisi++;
        else
        gecersizImeiSayisi++;

    } 
}
