#include "datathread.h"
#include "mainwindow.h"
#include <QColor>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DataThread threadData;
    w.setWindowTitle("Data Acquisition System");
    QIcon icon = QIcon(":/new/res/icon.png");
    w.setWindowIcon(icon);
    threadData.start();

    QObject::connect( & threadData, SIGNAL( sendVoltage(int,int,double) ),&w, SLOT( updateValue(int,int,double) ) );
    QObject::connect( & threadData, SIGNAL( sendTemp(int,int,double) ),&w, SLOT( updateTempValue(int,int,double) ) );
    QObject::connect( & w, SIGNAL( setPortSignal(QString,int)) ,&threadData, SLOT( setPort(QString,int) ) );
    QObject::connect( & threadData, SIGNAL( portOpen(bool)) ,&w, SLOT( portStatus(bool) ) );

    QObject::connect( & threadData, SIGNAL( sendAveVoltage(double) ),&w, SLOT( updateAveVoltage(double) ) );
    QObject::connect( & threadData, SIGNAL( sendMaxVoltage(double) ),&w, SLOT( updateMaxVoltage(double) ) );
    QObject::connect( & threadData, SIGNAL( sendMinVoltage(double) ),&w, SLOT( updateMinVoltage(double) ) );

    QObject::connect( & threadData, SIGNAL( sendAveTemp(double) ),&w, SLOT( updateAveTemp(double) ) );
    QObject::connect( & threadData, SIGNAL( sendMaxTemp(double) ),&w, SLOT( updateMaxTemp(double) ) );
    QObject::connect( & threadData, SIGNAL( sendMinTemp(double) ),&w, SLOT( updateAveTemp(double) ) );

    QObject::connect( & threadData, SIGNAL( sendGraphTemp(int,int,int,int,int,int) ),&w, SLOT( updateGraphTemp(int,int,int,int,int,int) ) );
    QObject::connect( & threadData, SIGNAL( sendGraphVoltage(int,int,int,int,int,int) ),&w, SLOT( updateGraphVoltage(int,int,int,int,int,int) ) );
    w.show();//Maximized();

    return a.exec();
}
