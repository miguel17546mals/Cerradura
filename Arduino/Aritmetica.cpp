#include "Aritmetica.h"


static Punto Aritmetica::extmultEyP(uint64_t k,Punto P,BigNumber a,BigNumber p){
    float c,d;
    int i,n;
    uint64_t t;
    
    c=log10(k);
    d=log10(2);
    n=c/d + 1;
    int B[n];
    
    //DectoBin
    i=n-1;
    t=k;
    while(i>-1){
      B[i]=t%2;
      t=t/2;
      i--;
    }    
    //
     
    Punto Pc(0,0),R;
    R=sumaPyP(Pc,a,p);
    R.Print();
    for(i=0;i<n;i++){
      Serial.print("Bit ");
      Serial.println(B[i]);
      R=sumaPyP(R,a,p);
      if(B[i]==1){
        //Serial.println("R antes 1");
        //R.Print();
        R=sumaPyQ(R,P,p);
        R.Print();
      }else{
        //Serial.println("R antes 0");
        //R.Print(); 
        R.Print(); 
       } 

    }
    return R;
  }

static Punto Aritmetica::multEyP(uint64_t k,Punto P,BigNumber a,BigNumber p){
    unsigned int i=1;
    Punto temP;
    
    if (k==1){
      return P;
    }

    temP = sumaPyP(P,a,p);
    //temP.Print();
    if(k==2){
        return temP;       
     }
     //printBignum(k);
     //Serial.println();
     while(i<k-1){
        /*
        P.Print();
        temP.Print();
        */
        Serial.println(i);
        temP=sumaPyQ(temP,P,p);
        temP.Print();
        i++;
      }
     return temP; 
  }
static Punto Aritmetica::sumaPyP(Punto P,BigNumber a,BigNumber p){

  if(P.getX()==0 && P.getY() == 0){
      return P;
    }
  
  BigNumber l;
  BigNumber Rx;
  BigNumber Ry;
  
  //Serial.print("Lambda ");
  l=3*(P.getX()*P.getX()) + a;
  //printBignum (l);
  //Serial.println();
  l=l*ModularArith::invMod(2*P.getY(),p);
  //printBignum (l);
  //Serial.println();
  l=l%p;
  /*
  printBignum (l);
  Serial.println();
  */
  Rx=(-2*P.getX() + l*l)%p;
  
  if(Rx<0){
    Rx=Rx+p;
  }
  /*
  Serial.print("Rx ");
  printBignum (Rx);
  Serial.println();
*/
  Ry=(-P.getY()+l*(P.getX()-Rx))%p;
  
  if(Ry<0){
    Ry=Ry+p;
  }
/*
  Serial.print("Ry ");
  printBignum (Ry);
  Serial.println();

  //print_uint64_t(Ry);
  //Serial.println();
  */
  return Punto(Rx,Ry);
  }
static Punto Aritmetica::restaPyQ(Punto P, Punto Q){
  }
static Punto Aritmetica::sumaPyQ(Punto P, Punto Q,BigNumber p){
  if(P.getX()==0 && P.getY()==0 ){
      return Q;
    } 
  BigNumber l;
  BigNumber Rx;
  BigNumber Ry;
  
  //Serial.print("Lambda ");
  l=P.getY() - Q.getY();
  //printBignum (l);
  //Serial.println();  
  l=l*ModularArith::invMod((P.getX() - Q.getX() ) ,p);
  //printBignum (l);
  //Serial.println();  
  l=l%p; 
  //printBignum (l);
  //Serial.println();
  /*
  printBignum(P.getX() - Q.getX() );
  Serial.println();
  printBignum (ModularArith::invMod ((P.getX() - Q.getX() ) ,p));
  Serial.println();
  Serial.print("L:");
  printBignum (l);
  Serial.println();
*/
  Rx=(l*l -P.getX() - Q.getX())%p;

  if(Rx<0){
    Rx=Rx+p;
  }
  /*
  printBignum (Rx);
  Serial.println();
  */
  Ry=(-P.getY() + l*(P.getX() -Rx))%p;
 if(Ry<0){
    Ry=Ry+p;
  }
  /*
  printBignum (Ry);
  Serial.println();
  */
  return Punto(Rx,Ry);
  }
//String Aritmetica::bytesToBits(byte[] escalar){
//  }
