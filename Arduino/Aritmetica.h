#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <Arduino.h>
#include "Punto.h"
#include "Print.h"
#include "ModularArith.h"
#include "BigNumber.h"
#include <math.h>
#include <stdint.h>

class Aritmetica{
  public:
      static Punto extmultEyP(uint64_t k,Punto P,BigNumber a,BigNumber p);
      static Punto multEyP(uint64_t k,Punto P,BigNumber a,BigNumber p);
      static Punto sumaPyP(Punto P,BigNumber a,BigNumber p);
      static Punto restaPyQ(Punto P, Punto Q);
      static Punto sumaPyQ(Punto P, Punto Q,BigNumber p);
//      String bytesToBits(byte[] escalar);
};

#endif
