#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "cellblock.h"
#include "tempsensor.h"
#include "datathread.h"
#include "labelbox.h"
#include "qcustomplot.h"
#include "graph.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //CellBlock *cellArray[116];
    bool activateConnect[2] = {false,false};
    QGridLayout *gridLayout[5];
    QVBoxLayout *vertLayout[5];
    std::map<int, LabelBox *> cellArray[5];
    std::map<int, LabelBox *> tempArray[5];

    int tempSenorLimit[5]={6,7,6,7,9};
    int cellSize[5]={22,22,22,22,28};

    QCPBars *voltageRange;
    QCPBars *tempRange;
    QVector<double> voltageRangeData;
    QVector<double> tempRangeData;
    QVector<double> ticks;

public:
    explicit MainWindow(QWidget *parent = 0);
    void LayoutSetUp();
    void packCellSetUp();
    void tempSetUp();

    ~MainWindow();

public slots:
     void portStatus(bool);
     void updateValue(int tabNum, int cellNum, double voltage);
     void updateTempValue(int tabNum, int sensorNum, double temp);
     void updateMaxVoltage(double);
     void updateMaxTemp(double);
     void updateMinVoltage(double);
     void updateMinTemp(double);
     void updateAveTemp(double);
     void updateAveVoltage(double);
     void updateGraphVoltage(int, int , int, int, int, int);
     void updateGraphTemp(int, int , int, int, int, int);
private slots:
     void on_scan_ports_clicked();
     void on_connect_port_clicked();
     void on_port_list_activated(int index);
     void on_baud_rate_activated(int index);
signals:
    void setPortSignal(QString,int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
