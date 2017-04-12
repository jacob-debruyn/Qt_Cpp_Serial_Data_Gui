#include "pack.h"
#include "ui_pack.h"

Pack::Pack(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Pack)
{
    ui->setupUi(this);
}

Pack::~Pack()
{
    delete ui;
}
