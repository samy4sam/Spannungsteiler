#ifndef SPANNUNGSTEILERLOGIK_H
#define SPANNUNGSTEILERLOGIK_H

#include <QObject>

class SpannungsteilerLogik : public QObject
{
  Q_OBJECT
public:
  enum serieList
  {
    E3 = 3,
    E6 = 6,
    E12 = 12,
    E24 = 24,
    E48 = 48,
    E96 = 96,
    E192 = 192
  };
  SpannungsteilerLogik(QObject *parent = nullptr);
  void setVol1(float vol);
  void setVol2(float vol);
  void setCur(float cur);
  void setSerie(SpannungsteilerLogik::serieList);
  float getRes1() const;
  float getRes2() const;
  void reset();
  void doCalc();

private:
  int eSerie;
  float vol1;
  float vol2;
  float current;
  float res1;
  float res2;
  float selectResistor(float r) const;
  float calcSerieValue(int i) const;

signals:
  void changedRes1(float value);
  void changedRes2(float value);
};

#endif // SPANNUNGSTEILERLOGIK_H
