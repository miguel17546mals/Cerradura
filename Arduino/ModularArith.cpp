#include "ModularArith.h"  
#include "Print.h" 
//Método Que obtiene el Máximo Comun Divisor
static BigNumber ModularArith::MCD(BigNumber a,BigNumber b){
    while ( b != 0) {
        uint64_t r = a % b;
        a = b;
        b = r;
    }
    return a;  
 }

//static uint64_t ModularArith::extMCD(uint64_t a,uint64_t b){}

static BigNumber ModularArith::invMod(BigNumber a,BigNumber b){

/*
  BigNumber x=1,y=0;
  BigNumber xLast=0,yLast=1;
  BigNumber q,r,m,n;
  while( a !=0 ){
    q=b/a;
    r=b%a;
    m=xLast - q*x;
    n=yLast - q*x;
    xLast=x;
    yLast=y;
    x=m;
    y=n;
    b=a;
    a=r;
    }
   if(x==1){
        return (xLast+b)%b;
    }else{
      return 0;
    }
}
*/  
  if (a<0){
    a=a+b;
  }

  printBignum (a);
  Serial.print(" mod ");
  printBignum (b);
  Serial.println(); 

  BigNumber c1=1;
  BigNumber c2=-(b/a);
  BigNumber t1=0;
  BigNumber t2 =1;
  BigNumber r=b%a;
  BigNumber x=a,y=r,c;
  while (r!=0){
    c=x/y;
    r=x%y;
    c1*=-c;
    c2*=-c;
    c1+=t1;
    c2+=t2;
    t1=-(c1-t1)/c;
    t2=-(c2-t2)/c;
    x=y;
    y=r; 
    }
    if(x==1){
        if(t2<0){
            Serial.print("Inv ");
            printBignum(t2+b);
            Serial.println();
            return t2+b;
         }
            Serial.print("Inv ");
            printBignum(t2);
            Serial.println();
        return t2;
    }else{
      return 0;
    }

  
}
/*
static uint64_t ModularArith::modPower(uint64_t m,uint64_t e,uint64_t a){}
static uint64_t ModularArith::sqrtP(uint64_t res,uint64_t p){}
static uint64_t ModularArith::complexSqrtP(uint64_t res,uint64_t q,uint64_t p){}
static uint64_t ModularArith::findNonResidue(uint64_t p){}
static bool ModularArith::sqrtPQ(uint64_t [] roots,uint64_t res,uint64_t p,uint64_t q){}
static bool ModularArith::pollardRho(uint64_t [] factors,uint64_t n,int runLenght){}
static bool ModularArith::millerRabinPrimeCheck(uint64_t p,int Size){}  
*/
