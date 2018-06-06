#ifndef CODIFICAR_H
#define CODIFICAR_H

#include "Punto.h"
#include "BigNumber.h"

class Codificar{
  private:
    BigNumber h;
    BigNumber m;
    BigNumber n;
    BigNumber X;
    BigNumber Y;
    BigNumber a;
    BigNumber b;
  public:
    Codificar(BigNumber CofA,BigNumber CofB,BigNumber n);
    void generaMyH(BigNumber n);
    Punto codifica(char letra);
    char decodifica(Punto p);
    //Geters y Setters
    void setH(BigNumber H);
    void setM(BigNumber M);
    void setN(BigNumber N);
    void setX(BigNumber X);
    void setY(BigNumber Y);
    void setA(BigNumber A);
    void setB(BigNumber B);
    BigNumber getH();
    BigNumber getM();
    BigNumber getN();
    BigNumber getX();
    BigNumber getY();
    BigNumber getA();
    BigNumber getB();
 
};

#endif
