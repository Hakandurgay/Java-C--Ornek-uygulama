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



public class KimlikNo {
     private  int [] tcKimlikNo;
    Rastgele random;
    private long kontrolTc;
    private String tc;
    private int[] tcKontrol;
      private int gecerliSayac;
        private int gecersizSayac;
    
    KimlikNo()
    {
        tcKimlikNo=new int[11];
        tcKontrol=new int[11];
        random=new Rastgele(10);
        tc="";
        gecerliSayac=0;
        gecersizSayac=0;
    }
    public String tcKimlikNoGetir()
            
    {
      tcKimlikNoUret();
      return stringeCevir();       
            
    }
    private String stringeCevir()
    {
                tc="";
        for (int i = 0; i < 11; i++) 
              tc+=tcKimlikNo[i];
            return tc;
    }
    public void tcKontrolEt() throws FileNotFoundException
    {
        gecerliSayac=0;
        gecersizSayac=0;
        kisilerDosyasiniOkuKontrol();
        System.err.println("Gecerli Tc Kimlik Numarasi Sayisi: "+gecerliSayac);
        System.err.println("Gecersiz Tc Kimlik Numarasi Sayisi: "+gecersizSayac);
    }
    private void kisilerDosyasiniOkuKontrol() throws FileNotFoundException
    {
        long tc;
        int sayac=0;
        java.io.File dosyaOku = new java.io.File("Kisiler.txt");  //int deger okuma 
          Scanner oku = new Scanner(dosyaOku);

           while (oku.hasNext())  
          {
              
              if(sayac%6==0) 
              {
                  long tempTc =oku.nextLong();
                  if(tcKimlikNoKontrol(tempTc))        
                      gecerliSayac++;
                  else
                      gecersizSayac++;
              }      
              else
              oku.next();
                            sayac++;
          }
           oku.close();
           
    }
          
    private boolean  tcKimlikNoKontrol(long tcKimlik)
    {
        this.kontrolTc=tcKimlik;  
        int index=10;
        
        do{
               if(index==-1)      //11 rakamdan fazla olup olmadığı burada kontrol ediliyor
                 return false;
               else
               {
                      tcKontrol[index]=(int)(kontrolTc % 10);
            kontrolTc /= 10;
            index--;
               }    
        } while  (kontrolTc > 0);

        int birinciKontrol_tekToplam=0;
        int birinciKontrol_ciftToplam=0;
         int birinciKontrol=0;    //1,3,5,7,9. basamağın 7 ile çarpımı ile 2,4,6,8. basamağın 9 ile çarpımının 10'a bölümünden kalanının      
         int ikinciKontrol=0;    //ilk basamağın sıfır olup olmadığı kontrol ediliyor
         int ucuncuKontrol=0;   //ilk on basamağın toplamının mod değerinin, 11. basamağa eşit olup olmadığı kontrol ediliyor

        for (int i=0;i<9;i+=2) //basamak değerleri toplanıyor
                birinciKontrol_tekToplam +=tcKontrol[i];
         for (int i=1;i<8;i+=2) 
                birinciKontrol_ciftToplam += tcKontrol[i];
       birinciKontrol=((birinciKontrol_ciftToplam*9)+(birinciKontrol_tekToplam*7))%10;

       ikinciKontrol=tcKontrol[0];
       for(int i=0;i<10;i++) //ilk on basamak toplanıyor
                    ucuncuKontrol+= tcKontrol[i];
       ucuncuKontrol=ucuncuKontrol%10;
       if(birinciKontrol==tcKontrol[9] && ikinciKontrol!=0  && ucuncuKontrol==tcKontrol[10])
               return true;
       else
               return false;
    }
    
    private void tcKimlikNoUret()
    {                  
         int birinciBasamak=(int)random.randomDegerGetir();
            if(birinciBasamak==0)
               birinciBasamak++;
      tcKimlikNo[0]=birinciBasamak;

        for (int i=1;i<9;i++)
        {   
          tcKimlikNo[i]=((int)random.randomDegerGetir());
        }
        
        int birinciKural_ciftSayilar = 0; //1-3-5-7-9 basamak toplamanın 7 ile çarpımı ile 2-4-6-8. basamağın 9 ile çarpımının 10'a bölümünden kalan rakam 10. basamaktaki ile aynı olmalı.
            
        for (int i=0;i<9;i+=2) //basamak değerleri toplanıyor
                birinciKural_ciftSayilar +=tcKimlikNo[i];

            int birinciKural_tekSayilar = 0;
            for (int i=1;i<8;i+=2) 
                birinciKural_tekSayilar += tcKimlikNo[i];

               int onuncuBasamaktakiSayi = (birinciKural_ciftSayilar * 7-birinciKural_tekSayilar) % 10;

                tcKimlikNo[9]=onuncuBasamaktakiSayi;

                  int  ikinciKural=0; //ilk on basamaktaki sayiların toplamının 10'a bölümünden kalan sayı 11. basamaktakine eşittir.
                for(int i=0;i<10;i++) //ilk on basamak toplanıyor
                    ikinciKural+= tcKimlikNo[i];

                ikinciKural= ikinciKural % 10;
                  tcKimlikNo[10]=ikinciKural;    
        }
}
