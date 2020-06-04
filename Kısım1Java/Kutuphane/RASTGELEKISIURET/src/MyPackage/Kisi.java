
package MyPackage;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Kisi {
    private final String dosyaYolu;
    private String telefonVeImeiNumarasi;
    private String tcNo;  
    private  KimlikNo tc;
    private  String adSoyad;
    private  int yas;
    private  Telefon telefon;  //imei ve telefon birlikte geliyor
    private String bilgiler;
  Rastgele ran;
  Rastgele rastgeleAdSoyad;
 ArrayList<String> kisiler;
    Kisi() throws FileNotFoundException
    {
       tc=new KimlikNo();
       telefon=new Telefon();
       ran=new Rastgele(100);
       kisiler=new ArrayList<String>();
       dosyaYolu="isimler.txt";
       rastgeleAdSoyad=new Rastgele(dosyaSatirSayisiBul());
       bilgiler="";
    }
    public void kisiUret() throws FileNotFoundException, IOException
    {
        tcNo= tc.tcKimlikNoGetir();
        yas=(int)ran.randomDegerGetir();
        telefonVeImeiNumarasi=telefon.telefonVeImeiGetir();
        adSoyad=rastgeleAdSoyadGetir();  
      
        bilgiler=tcNo+" "+adSoyad+yas+" "+telefonVeImeiNumarasi;
        kisiler.add(bilgiler);
    }
    public void kisileriDosyayaYaz() throws IOException
    {
         File file = new File("Kisiler.txt");
        if (!file.exists()) {
            file.createNewFile();
        }

        FileWriter fileWriter = new FileWriter(file,false);
        BufferedWriter bWriter = new BufferedWriter(fileWriter);

        for(String kisi:kisiler)
        {
               bWriter.write(kisi.toString());
                        bWriter.newLine();
        }
        bWriter.close();
    }
    private int dosyaSatirSayisiBul() throws FileNotFoundException //isimler dosyasının satır sayısı bulunuyor
    {
         java.io.File dosyaSatirSayisi = new java.io.File(dosyaYolu);
          Scanner satir = new Scanner(dosyaSatirSayisi);
          int satirSayisi=0;
  

          while (satir.hasNext())  //her satır bitiminde sayac bir arttırılıyor
          {
              satirSayisi++;                 
              satir.nextLine();
          }    
          return satirSayisi+1;
    }
    private String rastgeleAdSoyadGetir() throws FileNotFoundException
    {
            int rastgeleSatir=0;
            int sayac=0;
            String isim="";

            while(rastgeleSatir==0)
                    rastgeleSatir=(int)rastgeleAdSoyad.randomDegerGetir();
   
           java.io.File dosyakOku = new java.io.File("isimler.txt");
          Scanner input = new Scanner(dosyakOku);
          while (input.hasNext())  
          {
              sayac++;
              if(sayac==rastgeleSatir)        
            isim = input.nextLine()+ " ";
              else
                  input.nextLine();
                    
          }
          return isim;
    }
  }
    
    

