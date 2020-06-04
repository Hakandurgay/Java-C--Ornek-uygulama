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
import java.io.IOException;
import java.util.Scanner;

public class RastgeleKisi {

    private int kisiSayisi;
   Kisi kisi;

    public RastgeleKisi() throws FileNotFoundException
    {
        kisi=new Kisi();
    }
    public void islemYap() throws IOException
    {
        int secim;
        do{
              System.err.println("1- Rastgele Kisi Uret");
              System.err.println("2- Uretilmis Dosya Kontrol Et");
              System.err.println("3- Cikis");
              Scanner menuSec=new Scanner(System.in);
              secim=menuSec.nextInt();
              if(secim==1)
                  kisiUret();
              else if(secim==2)
                  dosyaKontrolEt();
              
        }while(secim!=3);
    }
    private void kisiUret() throws IOException
    {
        
        System.out.println("Kac tane kisi uretmek istiyorsunuz");
        Scanner kisiAl=new Scanner(System.in);
        kisiSayisi=kisiAl.nextInt();
        
       
                for (int i = 0; i < kisiSayisi; i++) {       
                    kisi.kisiUret();     
           }
             kisi.kisileriDosyayaYaz();
    }
    private void dosyaKontrolEt() throws FileNotFoundException
    {
        KimlikNo tcKontrol=new KimlikNo();
        System.err.println("TC KIMLIK KONTROL");
        IMEINo imeiKontrol=new IMEINo();

        tcKontrol.tcKontrolEt();
                System.err.println("IMEI KONTROL");

        imeiKontrol.imeiNoKontrol();
    }
}
