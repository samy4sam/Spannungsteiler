/*!
 * @file SpannungsteilerLogik.h
 * @author Philip Zellweger (philip.zellwegerhsr.ch)
 * @brief Implementation of class SpannungsteilerLogik
 * @version 1.0
 * @date 2019-11-28
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SPANNUNGSTEILERLOGIK_H
#define SPANNUNGSTEILERLOGIK_H

#include <QObject>

//!  SpannungsteilerLogik class.
/*!
  This class calculates resistor R1 and R2 depending on the voltage 1, voltage 2
  and the current .
*/

class SpannungsteilerLogik : public QObject
{
  Q_OBJECT

 public:
  //! serieList is an enumtype
  /*! serieList allows to choose the E-Reihe and is needed to evaluate the
   * Resistors R1 & R2 */
  enum serieList
  {
    E3 = 3,    /*!< Enum E3 value 3. */
    E6 = 6,    /*!< Enum E6 value 6. */
    E12 = 12,  /*!< Enum E12 value 12. */
    E24 = 24,  /*!< Enum E24 value 24. */
    E48 = 48,  /*!< Enum E48 value 48. */
    E96 = 96,  /*!< Enum E96 value 96. */
    E192 = 192 /*!< Enum E192 value 192. */
  };

  //! SpannungsteilerLogik constructor.
  /*!
    This ctor takes a default parameter parent to initialize the parent QObject.
    It also initialize all member variables with the value 0.0 except eSerie.
    In this case the parent QObject ist set to nullptr.
    \param parent is a QObject pointer set to nullptr.
  */
  SpannungsteilerLogik(QObject* parent = nullptr);

  //! A setter member function.
  /*!
    This member function allows to overwrite the member variable vol1 .
    \param vol the first argument.
  */
  void setVol1(double vol);

  //! A setter member function.
  /*!
    This member function allows to overwrite the member variable vol2 .
      \param vol the first argument.
  */
  void setVol2(double vol);

  //! A setter member function.
  /*!
    This member function allows to overwrite the member variable cur .
    \param cur the first argument.
  */
  void setCur(double cur);

  //! A setter member function.
  /*!
    This member function allows to choose the E-Reihe .
    \param serie the first argument.
  */
  void setSerie(serieList serie);

  //! A getter member function.
  /*!
    This member function returns the resistor R1 .
    \return the resistor 1 value
  */
  double getRes1() const;

  //! A getter member function.
  /*!
    This member function returns the resistor R2 .
    \return the resistor 2 value
  */
  double getRes2() const;

  //! A reset member function.
  /*!
    This member function allows to set all values to 0.0 except the member
    variable eSerie.
  */
  void reset();

  //! A calculation member function.
  /*!
    This member function calculates the resistor R1 and R2 depending on voltage
    1 voltage 2 and the current .
  */
  void doCalc();

 signals:

  //! A signal function.
  /*!
   This signal function tells the widget ui to update the resistor R1 value
    \param resValue1 the first argument.
  */
  void changedRes1(double resValue1);

  //! A signal function.
  /*!
  This signal function tells the widget ui to update the resistor R2 value
    \param resValue2 the first argument.
  */
  void changeRes2(double resValue2);

  //! A signal function.
  /*!
     This signal function tells the widget ui to set all shown values to 0.0
    \param nullValue the first argument.
  */
  void setNull(double nullValue);

 private:
  serieList eSerie;
  double vol1;
  double vol2;
  double current;
  double res1;
  double res2;
  double selectResistor(double r) const;
  double calcSerieValue(int i) const;
};

#endif  // SPANNUNGSTEILERLOGIK_H
