#include "spannungsteilerwidget.h"
#include "ui_spannungsteilerwidget.h"

SpannungsteilerWidget::SpannungsteilerWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SpannungsteilerWidget)
{
  ui->setupUi(this);

  // **** Interaktives Verhalten initialisieren *** :
  // qOverload damit Compiler weiss ob double oder String

  connect(ui->U1Box, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setVol1);

  connect(ui->U2Box, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setVol2);

  connect(ui->StromBox, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setCur);

  connect(ui->EReihe_Box, &QComboBox::currentTextChanged, &spannungsteiler,
          &SpannungsteilerLogik::setSerie);

  connect(ui->CalcButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::doCalc);

  connect(ui->ResetButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::reset);

  connect(&spannungsteiler, &SpannungsteilerLogik::changedRes1,
          ui->Widerstand1Box, qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::changedRes2,
          ui->Widerstand2Box, qOverload<double>(&QDoubleSpinBox::setValue));
}

SpannungsteilerWidget::~SpannungsteilerWidget()
{
  delete ui;
}
