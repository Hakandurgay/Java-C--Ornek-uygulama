/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
package MyPackage;


public class Rastgele {
     private long max;
      private long last;                            
      long sayac;
      private  long deger;
      public Rastgele(int max)
      {
          sayac=0;
          deger=999983; //6 haneli asal sayı seçtim
          this.max = max;
          last = (int) (System.currentTimeMillis() % max);
      }
public long randomDegerGetir(){
        sayac++;
      if(sayac==deger)
        deger= deger*2; 
        last = (last * 999979  + 3) % deger;
        return last % max;
    }
}
