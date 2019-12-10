/*!
 * \file SpannungsteilerWidget.h
 */

#ifndef SPANNUNGSTEILERWIDGET_H
#define SPANNUNGSTEILERWIDGET_H

#include <SpannungsteilerLogik.h>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class SpannungsteilerWidget;
}
QT_END_NAMESPACE

//!  SpannungsteilerWidget class generates an user interface.
/*!
  This class implements an user interface to interact with the user.
  There are three fields, each of them take a double value to set the input
  voltage U1, input voltage U2 and input current I. The user interface also
  allows to set the E-Reihe value in a drop down list.
  The "Berechnen" button starts the calculation, the resuls are shown in the
  picture and fields on the right side. The reset button sets all values to 0.0.
*/
class SpannungsteilerWidget : public QWidget
{
  Q_OBJECT

 public:
  //! SpannungsteilerWidget constructor.
  /*!
    This ctor takes a default parameter "parent" to initialize the parent
    QWidget. The main task of this ctor is to enable functionality between the
    shown values and slots funtions in the SpannungsteilerLogik class. In this
    case the parent QWidget is set to nullptr.
    \param parent is a QWidget pointer set to nullptr.
  */
  SpannungsteilerWidget(QWidget* parent = nullptr);

  //! SpannungsteilerLogik destructor.
  ~SpannungsteilerWidget();

 private:
  Ui::SpannungsteilerWidget* ui;
  SpannungsteilerLogik spannungsteiler;

 private slots:
  void onEReiheChanged();
  void drawValues(void) const;
};
#endif  // SPANNUNGSTEILERWIDGET_H
