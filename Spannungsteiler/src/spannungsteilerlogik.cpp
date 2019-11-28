/**
 * @file spannungsteilerlogik.cpp
 * @author Philip Zellweger (philip.zellwegerhsr.ch)
 * @brief Implementation of class SpannungsteilerLogik
 * @version 1.0
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "spannungsteilerlogik.h"
#include <QtDebug>
#include <cassert>
#include <cmath>

//=========PUBLIC=====================================================================
SpannungsteilerLogik::SpannungsteilerLogik(QObject* parent)
    : QObject(parent), vol1(0.0), vol2(0.0), current(0.0), res1(0.0), res2(0.0)
{
}

void SpannungsteilerLogik::setVol1(double vol)
{
  vol1 = vol;
  qDebug() << "Spannung 1 = " << vol1;
}

void SpannungsteilerLogik::setVol2(double vol)
{
  vol2 = vol;
  qDebug() << "Spannung 2 = " << vol2;
}

void SpannungsteilerLogik::setCur(double cur)
{
  current = cur;
  qDebug() << "Strom  = " << cur;
}

void SpannungsteilerLogik::setSerie(serieList serie)
{
  eSerie = serie;
  qDebug() << "E-Serie = " << eSerie;
}

double SpannungsteilerLogik::getRes1() const
{
  return res1;
}

double SpannungsteilerLogik::getRes2() const
{
  return res2;
}

void SpannungsteilerLogik::reset()
{
  vol1 = 0.0;
  vol2 = 0.0;
  res1 = 0.0;
  res2 = 0.0;
  current = 0.0;
  emit setNull(vol1);
}

void SpannungsteilerLogik::doCalc()
{
  assert(vol1 > vol2);
  double r1tmp = vol1 / current;
  double r2tmp = (r1tmp * vol2) / (vol1 - vol2);
  res1 = selectResistor(r1tmp);
  res2 = selectResistor(r2tmp);
  qDebug() << "Resistor 1 = " << res1;
  qDebug() << "Resistor 2 = " << res2;
  emit changedRes1(res1);
  emit changeRes2(res2);
}

double SpannungsteilerLogik::selectResistor(double r) const
{
  double coeff = pow(10.0, int(log10(r)));
  for (int i = 0; i < eSerie; ++i)
  {
    if ((coeff * calcSerieValue(i)) > r)
    {
      if ((coeff * calcSerieValue(i) - r) < (r - coeff * calcSerieValue(i - 1)))
      {
        return coeff * calcSerieValue(i);
      }
      else
      {
        return coeff * calcSerieValue(i - 1);
      }
    }

    if ((i == eSerie - 1) && (coeff * calcSerieValue(i) < r))
    {
      if ((coeff * 10.0 * calcSerieValue(i - eSerie + 1) - r) >
          (r - coeff * calcSerieValue(i)))
      {
        return coeff * calcSerieValue(i);
      }
      else
      {
        return coeff * calcSerieValue(i - eSerie + 1);
      }
    }
  }
  return 0;
}

double SpannungsteilerLogik::calcSerieValue(int i) const
{
  double value = pow((pow(10.0, i)), (1.0 / eSerie));

  if ((E3 <= eSerie) && (eSerie <= E24))
  {
    if ((2.2 < value) && (value < 4.7))
    {
      value += 0.1;
    }
    if ((round(value)) == 8)
    {
      value -= 0.1;
    }
  }

  if (eSerie < E48)
  {
    value = round(value * 10) / 10.0;
  }

  else
  {
    value = round(value * 100) / 100.0;
  }

  return value;
}
