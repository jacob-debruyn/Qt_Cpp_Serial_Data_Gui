#include "tempsensor.h"
#include "ui_tempsensor.h"

TempSensor::TempSensor(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::TempSensor)
{
    ui->setupUi(this);
    QPixmap pix( ":/new/res/thermometer.png" );
    ui->icon->setScaledContents(true);
    ui->icon->setPixmap(pix);
}
void TempSensor::setTemp(double t){
   ui->temp->setText(QString::number(t));
}
TempSensor::~TempSensor()
{
    delete ui;
}
