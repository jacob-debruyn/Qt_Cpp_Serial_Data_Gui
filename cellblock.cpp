#include "cellblock.h"
#include "ui_cellblock.h"

CellBlock::CellBlock(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::CellBlock)
{
    ui->setupUi(this);
    QPixmap pix( ":/new/res/batteryIcon2.png" );
    ui->icon->setScaledContents(true);
    ui->icon->setPixmap(pix);
}

void CellBlock::setVoltage(double v){
   ui->voltage->setText(QString::number(v));
}

CellBlock::~CellBlock()
{
    delete ui;
}
