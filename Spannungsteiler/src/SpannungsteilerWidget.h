/*!
 * @file SpannungsteilerWidget.h
 * @author Ivan Inderbitzin
 * @brief
 * @version 1.0
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
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

/*!
 * @brief class SpannungsteilerWidget new Spannungsteiler widget
 *
 */
class SpannungsteilerWidget : public QWidget
{
  Q_OBJECT

 public:
  /*!
   * @brief Construct a new Spannungsteiler Widget object
   *
   * @param parent - QWidget*
   */
  SpannungsteilerWidget(QWidget* parent = nullptr);
  /*!
   * @brief Destroy the Spannungsteiler Widget object
   *
   */
  ~SpannungsteilerWidget();

 private:
  Ui::SpannungsteilerWidget* ui;
  SpannungsteilerLogik spannungsteiler;

 private slots:
  void onEReiheChanged();
  void drawValues(void) const;
};
#endif  // SPANNUNGSTEILERWIDGET_H
