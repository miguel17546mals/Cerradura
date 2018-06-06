#include "Punto.h"

Punto::Punto(){
  this->x=0;
  this->y=0;
}
Punto::Punto(BigNumber x,BigNumber y){
  this->x=x;
  this->y=y;
}
void Punto::setX(BigNumber x){this->x=x;}
void Punto::setY(BigNumber y){this->y=y;}
BigNumber Punto::getX(){return this->x;}
BigNumber Punto::getY(){return this->y;}
void Punto::Print(){
  Serial.print("(");
  printBignum(this->x);
  Serial.print(",");
  printBignum(this->y); 
  Serial.print(")");
  Serial.println();
}
