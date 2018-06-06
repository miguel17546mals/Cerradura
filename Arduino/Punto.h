#ifndef PUNTO_H
#define PUNTO_H

#include <Arduino.h>
#include "Print.h"

class Punto{
  private:
      BigNumber x;
      BigNumber y;
  public:
    Punto();
    Punto(BigNumber x,BigNumber y);
    void setX(BigNumber x);
    void setY(BigNumber y);
    BigNumber getX();
    BigNumber getY();
    void Print();
};

#endif
