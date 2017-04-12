#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <QGroupBox>

namespace Ui {
class TempSensor;
}

class TempSensor : public QGroupBox
{
    Q_OBJECT

public:
    explicit TempSensor(QWidget *parent = 0);
     void changeTitle(QString X){setTitle(X);}
     void setTemp(double t);
    ~TempSensor();

private:
    Ui::TempSensor *ui;
};

#endif // TEMPSENSOR_H
