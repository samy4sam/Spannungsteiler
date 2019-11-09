#include <cmath>
#include"Spannungsteiler.h"

using namespace std;

Spannungsteiler::Spannungsteiler():
  vol1(0),vol2(0),current(0),res1(0),res2(0)
{}

void Spannungsteiler::setVol1(float vol){
  this->vol1 = vol;
}

void Spannungsteiler::setVol2(float vol){
  this->vol2 = vol;
}

void Spannungsteiler::setCur(float cur){
  this->current = cur;
}

void Spannungsteiler::setERow(enum Spannungsteiler::erow er){
  this->erowValue = er;
}

float Spannungsteiler::getRes1() const
{
  return this->res1;
}

float Spannungsteiler::getRes2() const
{
  return this->res2;
}

void Spannungsteiler::reset()
{
  this->vol1 = 0;
  this->vol2 = 0;
  this->res1 = 0;
  this->res2 = 0;
  this->current = 0;
}

void Spannungsteiler::doCalc(){
}

float Spannungsteiler::selectRes(float r) const{
  float coeff = pow(10,int(log10(r)));
  for(int i=0;i<this->erowValue;++i){
    if(coeff*calcERowVal(i)>r){
      if(coeff*calcERowVal(i)-r < r-coeff*calcERowVal(i-1))
      {
        return coeff*calcERowVal(i);
      }
      else
      {
        return coeff*calcERowVal(i-1);
      }
    }
    if((i==erowValue-1) && (coeff*calcERowVal(i)<r)){
      if(coeff*10*calcERowVal(i-erowValue+1)-r>r-coeff*calcERowVal(i))
      {
        return coeff*calcERowVal(i);
      }
      else
      {
        return coeff*calcERowVal(i-erowValue+1);
      }
    }
  }
}

float Spannungsteiler::calcERowVal(int i) const
{
  return pow(pow(10,i),1.0/this->erowValue);
}
