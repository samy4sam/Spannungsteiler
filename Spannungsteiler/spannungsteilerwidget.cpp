#include "spannungsteilerwidget.h"
#include "ui_spannungsteilerwidget.h"

SpannungsteilerWidget::SpannungsteilerWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SpannungsteilerWidget)
{
  ui->setupUi(this);

  // **** Interaktives Verhalten initialisieren ***

  //
  // **************************************************************************
  // SetValues

  connect(ui->U1Box, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setVol1);

  connect(ui->U2Box, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setVol2);

  connect(ui->StromBox, qOverload<double>(&QDoubleSpinBox::valueChanged),
          &spannungsteiler, &SpannungsteilerLogik::setCur);

  connect(ui->EReihe_Box, &QComboBox::currentTextChanged, this,
          &SpannungsteilerWidget::onEReiheChanged);

  ui->EReihe_Box->addItem("E3", static_cast<int>(SpannungsteilerLogik::E3));
  ui->EReihe_Box->addItem("E6", static_cast<int>(SpannungsteilerLogik::E6));
  ui->EReihe_Box->addItem("E12", static_cast<int>(SpannungsteilerLogik::E12));
  ui->EReihe_Box->addItem("E24", static_cast<int>(SpannungsteilerLogik::E24));
  ui->EReihe_Box->addItem("E48", static_cast<int>(SpannungsteilerLogik::E48));
  ui->EReihe_Box->addItem("E96", static_cast<int>(SpannungsteilerLogik::E96));
  ui->EReihe_Box->addItem("E192", static_cast<int>(SpannungsteilerLogik::E192));

  //
  //***************************************************************************
  // Calculation

  connect(ui->CalcButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::doCalc);

  //
  //***************************************************************************
  // Show Resistors Values

  connect(&spannungsteiler, &SpannungsteilerLogik::changedRes1,
          ui->Widerstand1Box, qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::changeRes2,
          ui->Widerstand2Box, qOverload<double>(&QDoubleSpinBox::setValue));
  //
  //***************************************************************************
  // Reset

  connect(ui->ResetButton, &QPushButton::clicked, &spannungsteiler,
          &SpannungsteilerLogik::reset);

  connect(&spannungsteiler, &SpannungsteilerLogik::setNull, ui->U1Box,
          qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::setNull, ui->U2Box,
          qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::setNull, ui->StromBox,
          qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::setNull, ui->Widerstand1Box,
          qOverload<double>(&QDoubleSpinBox::setValue));

  connect(&spannungsteiler, &SpannungsteilerLogik::setNull, ui->Widerstand2Box,
          qOverload<double>(&QDoubleSpinBox::setValue));
}
//
//*****************************************************************************
// Private Slots

void SpannungsteilerWidget::onEReiheChanged()
{
  spannungsteiler.setSerie(static_cast<SpannungsteilerLogik::serieList>(
      ui->EReihe_Box->currentData().value<int>()));
}

//
//*****************************************************************************
// Destructor

SpannungsteilerWidget::~SpannungsteilerWidget()
{
  delete ui;
}
