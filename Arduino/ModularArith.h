#ifndef MODULARARITH_H
#define MODULARARITH_H

#include "BigNumber.h"
class ModularArith{
  
  public:
    static BigNumber MCD(BigNumber a,BigNumber b);

    //static uint64_t extGCD(uint64_t a,uint64_t b);

    static BigNumber invMod(BigNumber a,BigNumber b);
    /*
    static uint64_t modPower(uint64_t m,uint64_t e,uint64_t a);
    static uint64_t sqrtP(uint64_t res,uint64_t p);
    static uint64_t complexSqrtP(uint64_t res,uint64_t q,uint64_t p);
    static uint64_t findNonResidue(uint64_t p);
    static bool sqrtPQ(uint64_t [] roots,uint64_t res,uint64_t p,uint64_t q);
    static bool pollardRho(uint64_t [] factors,uint64_t n,int runLenght);
    static bool millerRabinPrimeCheck(uint64_t p,int Size); 
    */ 
};



#endif

