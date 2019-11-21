#ifndef SPANNUNGSTEILERWIDGET_H
#define SPANNUNGSTEILERWIDGET_H

#include <spannungsteilerlogik.h>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class SpannungsteilerWidget;
}
QT_END_NAMESPACE

class SpannungsteilerWidget : public QWidget
{
  Q_OBJECT

 public:
  SpannungsteilerWidget(QWidget* parent = nullptr);
  ~SpannungsteilerWidget();

 private:
  Ui::SpannungsteilerWidget* ui;
  SpannungsteilerLogik spannungsteiler;

 private slots:
  void onEReiheChanged();
};
#endif  // SPANNUNGSTEILERWIDGET_H
