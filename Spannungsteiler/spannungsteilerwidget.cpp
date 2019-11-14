#include "spannungsteilerwidget.h"
#include "ui_spannungsteilerwidget.h"

SpannungsteilerWidget::SpannungsteilerWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SpannungsteilerWidget)
{
  ui->setupUi(this);

  // **** Interaktives Verhalten initialisieren *** :

  connect(ui->U1Box, &QSpinBox::valueChanged, &spannungsteiler,
          &SpannungsteilerLogik::setVol1);
  connect(ui->U2Box, &QSpinBox::valueChanged, &spannungsteiler,
          &SpannungsteilerLogik::setVol2);
  connect(ui->StromBox, &QSpinBox::valueChanged, &spannungsteiler,
          &SpannungsteilerLogik::setCur);
  connect(ui->EReihe_Box, &QComboBox::currentTextChanged, &spannungsteiler,
          &SpannungsteilerLogik::setSerie);

  connect(ui->CalcButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::doCalc);
  connect(ui->ResetButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::reset);

  connect(&, &Counter::valueChanged, ui->countLabel,
          qOverload<int>(
              &QLabel::setNum));  // setNum hat zwei Implementationen einmal mit
                                  // "double" und einmal mit "int"
                                  // Compiler weist nicht welche davon verwendet
                                  // werden muss daher brauchts den staticCast
                                  // mit "int" oder "double" typ.
}

SpannungsteilerWidget::~SpannungsteilerWidget()
{
  delete ui;
}
