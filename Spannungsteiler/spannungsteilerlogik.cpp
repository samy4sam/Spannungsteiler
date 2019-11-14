#include <cmath>
#include <cassert>
#include "spannungsteilerlogik.h"

SpannungsteilerLogik::SpannungsteilerLogik(QObject* parent) : 
QObject(parent),vol1(0),vol2(0),current(0),res1(0),res2(0)
{}

void SpannungsteilerLogik::setVol1(float vol){
  this->vol1 = vol;
}

void SpannungsteilerLogik::setVol2(float vol){
  this->vol2 = vol;
}

void SpannungsteilerLogik::setCur(float cur){
  this->current = cur;
}

void SpannungsteilerLogik::setSerie(enum SpannungsteilerLogik::serieList serie){
  this->eSerie = serie;
}

float SpannungsteilerLogik::getRes1() const
{
  return this->res1;
}

float SpannungsteilerLogik::getRes2() const
{
  return this->res2;
}

void SpannungsteilerLogik::reset()
{
  this->vol1 = 0;
  this->vol2 = 0;
  this->res1 = 0;
  this->res2 = 0;
  this->current = 0;
}

void SpannungsteilerLogik::doCalc(){
  assert(vol1>vol2);
  float r1tmp = vol1/current;
  float r2tmp = (r1tmp*vol2)/(vol1-vol2);
  this->res1 = selectResistor(r1tmp);
  this->res2 = selectResistor(r2tmp);
  emit changedRes1(res1);
  emit changedRes1(res2);
}

float SpannungsteilerLogik::selectResistor(float r) const{
  float coeff = pow(10.0,int(log10(r)));
  for(int i=0;i<eSerie;++i){

    if(coeff*calcSerieValue(i)>r){
      if(coeff*calcSerieValue(i)-r < r-coeff*calcSerieValue(i-1))
      {
        return coeff*calcSerieValue(i);
      }
      else
      {
        return coeff*calcSerieValue(i-1);
      }
    }
    if((i==eSerie-1) && (coeff*calcSerieValue(i)<r)){
      if(coeff*10.0*calcSerieValue(i-eSerie+1)-r>r-coeff*calcSerieValue(i))
      {
        return coeff*calcSerieValue(i);
      }
      else
      {
        return coeff*calcSerieValue(i-eSerie+1);
      }
    }
  }
  return 0;
}

float SpannungsteilerLogik::calcSerieValue(int i) const
{
  float value =  pow(pow(10.0,i),1.0/eSerie);
  if(serieList::E3<=eSerie && eSerie<=serieList::E24){
    if(2.2<value && value<4.7)
      value += 0.1;
    if(round(value) == 8)
      value -= 0.1;
  }
  if(eSerie<serieList::E48)
    value = round(value*10)/10.0;
  else
    value = round(value*100)/100.0;

  return value;
}