#include "spannungsteilerwidget.h"
#include "ui_spannungsteilerwidget.h"

SpannungsteilerWidget::SpannungsteilerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpannungsteilerWidget)
{
    ui->setupUi(this);
}

SpannungsteilerWidget::~SpannungsteilerWidget()
{
    delete ui;
}

