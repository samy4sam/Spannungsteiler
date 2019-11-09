
#include"Spannungsteiler.h"

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

