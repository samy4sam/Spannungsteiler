#ifndef SPANNUNGSTEILERLOGIK_H
#define SPANNUNGSTEILERLOGIK_H

#include <QObject>

class SpannungsteilerLogik : public QObject
{
  Q_OBJECT

 private:
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
  serieList eSerie;
  double vol1;
  double vol2;
  double current;
  double res1;
  double res2;
  double selectResistor(double r) const;
  double calcSerieValue(int i) const;

 signals:
  void changedRes1(double resValue1);
  void changeRes2(double resValue2);
  void setNull(double nullValue);

 public:
  SpannungsteilerLogik(QObject* parent = nullptr);
  void setVol1(double vol);
  void setVol2(double vol);
  void setCur(double cur);
  void setSerie(QString serie);
  double getRes1() const;
  double getRes2() const;
  void reset();
  void doCalc();
};

#endif  // SPANNUNGSTEILERLOGIK_H
