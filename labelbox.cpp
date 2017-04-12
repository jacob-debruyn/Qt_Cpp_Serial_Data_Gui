#include "labelbox.h"
#include "ui_labelbox.h"

LabelBox::LabelBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelBox)
{
    ui->setupUi(this);
}
void LabelBox::setLabel(QString s){
    ui->label->setText(s);
}
void LabelBox::setStatus(char type, double value){

    if(type=='c'){
        if(value>4){
            ui->status->setText(QString::number(value));
            ui->status->setStyleSheet(styleSheet().append(QString("background-color : orange;")) );
        }
        if(value>3&&value<4){
            ui->status->setText(QString::number(value));
            ui->status->setStyleSheet(styleSheet().append(QString("background-color : #00A88C;")) );
        }
        if(value<3){
            ui->status->setText(QString::number(value));
            ui->status->setStyleSheet(styleSheet().append(QString("background-color : red;")) );
        }
    }
    if(type=='t'){
        if(value>40){
            ui->status->setText(QString::number(value));
            ui->status->setStyleSheet(styleSheet().append(QString("background-color : red;")) );
        }
        if(value<4){
            ui->status->setText(QString::number(value));
            ui->status->setStyleSheet(styleSheet().append(QString("background-color : #00A88C;")) );
        }
    }


}


LabelBox::~LabelBox()
{
    delete ui;
}
