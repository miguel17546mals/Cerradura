#include "Mensaje.h"

/*
 * Método Codifica: Codifica un caracter conforme a la definición de la codificacion en curva elíptica.
 * Parametros:
 * char letra: Letra que se va a codificar.
 * long long h: Espaciamiento al momento de codificar.
 * long long a: Parámetro a de la curva elíptica.
 * long long b: Parámetro b de la curva elíptica.
 * long long p: Parámetro p de la curva elíptica.
 * Regresa un Punto de la curva donde se localiza lel caracter dado.
 */
static Punto Mensaje::Codifica(char letra,long long h,long long a,long long b,long long p){
  int c=letra-31 , i=1;
  /*
  Serial.print("Valor c:");
  Serial.println(c);
  Serial.print("Valor h:");
  print_int64_t(h);
  Serial.println();
  */
  long long y=0;
  long long x=0;
  do{
    x=c*h+i;
    /*
    Serial.print("X:");
    print_int64_t(x);
    Serial.println();
    */
    y=((x*x*x)+a*x+b)%p;
    /*
    Serial.print("Y=");
    print_int64_t(y);
    Serial.println();
    */
    y=ModularArith::SqrtMod(y,p);
    /*
    Serial.print("Congruencia resuelta :");
    print_int64_t(y);
    Serial.println();
    */
    i++;
  }while(y==0);
  return Punto(x,y); 
}
/*
 * Método Decodifica: Decodifica un Punto conforme a la definicion cifrado de curva elíptica.
 * Parámetros: 
 * Punto P : Punto de la curva que contiene la informacion del caracter.
 * long long h: Espaciamiento de los puntos en la curva.
 * Regresa el caracter decodificado.
 */
static char Mensaje::Decodifica(Punto p,long long h){
  Serial.println("Decodificando");
  int c;
  long long M,uno=1;
  M=(p.getX()-uno)/h;
  c=M;
  Serial.println(c);
  Serial.println("Ya estufas");
  return c;
}


