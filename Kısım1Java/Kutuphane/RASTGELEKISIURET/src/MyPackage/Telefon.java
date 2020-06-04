/**
*
* @author hakandurgay@gmail.com hakan durgay
* @since 26.04.2020
* <p>
* Açıklama
* </p>
*/
package MyPackage;

public class Telefon {
      
      private int[] telefon;
      Rastgele rand;
      String telefonVeImei;
      IMEINo imei;
    boolean bool;
 
    Telefon()
    {
        telefon=new int[11];
        rand=new Rastgele(10);
        imei=new IMEINo();
        telefonVeImei="";
        bool=true;
    }
 public String telefonVeImeiGetir()
 {
     telefonNoUret();
     imeiNoGetir();
     return telefonVeImei;
 }
 private void telefonNoUret()
 {
     telefon[0]=0;
     telefon[1]=5;
                                        
           while(bool)
           {
                telefon[2]=(int)rand.randomDegerGetir();
                if(telefon[2]==0 || telefon[2]==3 || telefon[2]==4 || telefon[2]==5|| telefon[2]==6)                         
                                 break;
           } 
           while(bool)
           {
               telefon[3]=(int)rand.randomDegerGetir();
                      if(telefon[2]==0)
                      {
                          if(telefon[3]==1 || telefon[3]==5 || telefon[3]==6 || telefon[3]==7)
                             break;
                      }
                      else if(telefon[2]==3)
                      {
                          break;
                      }
                      else if(telefon[2]==4)
                      {
                          break;
                      }
                      else if(telefon[2]==5)
                      {
                            if(telefon[3]==2 || telefon[3]==3 || telefon[3]==4 || telefon[3]==5||telefon[3]==9)
                             break;
                      }
                      else if(telefon[2]==6)
                      {
                          if(telefon[3]==1)
                              break;
                      }
            }

           for(int i=4; i<11;i++)
           {
                                telefon[i]=(int)rand.randomDegerGetir();
           }
    
 }
 private void imeiNoGetir()
 {
     telefonVeImei="";
      for (int i = 0; i < 11; i++) 
                {
                        telefonVeImei+=telefon[i];
                }                  
               telefonVeImei+=" ("+(imei.imeiNoGetir())+")";
 }
    
    
}
