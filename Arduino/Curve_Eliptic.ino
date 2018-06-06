#include <stdint.h>

#include "BigNumber.h"

#include "Print.h"
#include "Punto.h"
#include "Aritmetica.h"
#include "Codificar.h"
#include "ModularArith.h"

//static int DIGITS = 0;

class Curva
{ private:
    //Numero Primo 
    uint64_t p;
    //Parametros de la curva y^2 = x^3 +ax+b
    int a;
    int b;
    //Cofactor 
    int h;
    //Numero primo n
    uint64_t n;
    //Punto Inicial de la curva
    Punto G;
    Punto PointSelect(uint64_t p);
    
  public:
    Curva();
    int setH(uint64_t p);
};

Curva::Curva(){
  this->p=67280421310721;
  //print_uint64_t(this->p);
  this->a=0;
  //Serial.println(this->a);
  this->b=7;
  //Serial.println(this->b); 
  this->n=6728042131087;
  //Serial.println(this->n); 
  this->h=setH(this->p);
  //Serial.println(this->h); 
  this->G=PointSelect(this->p);
  }
int Curva::setH(uint64_t p){
  uint64_t numE;
  numE=p+1+(2*sqrt(p));
  print_uint64_t(numE);
  return numE/this->n;
  }
Punto Curva::PointSelect(uint64_t p){
  uint64_t x;
  uint64_t y;
}


BigNumber O(BigNumber p ){
    //return p+1+2*sqrt(p);
    return p;
  }
void setup() {
Serial.begin(9600);
BigNumber::begin ();


Punto P(0,0);
Punto Q(1,3);

Punto P2,P3;

P3=Aritmetica::extmultEyP(1275,P,0,67280421310721);
P3.Print();


}

void loop() {

}
