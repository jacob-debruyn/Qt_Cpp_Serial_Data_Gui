#ifndef THREAD_H
#define THREAD_H
#include <QtCore>
#include <QSerialPort>
#include <string>
#include <string.h>

class DataThread : public QThread
{
     Q_OBJECT
     QSerialPort serialPort;
     QTimer timer;
     QString portName;
     double maxVoltage;
     double maxTemp;
     double minVoltage;
     double minTemp;
     double cellTotal;
     double aveVoltage;
     double aveTemp;
     int cellCounter;
     int tempCounter;
     int voltageRanges[6];
     int tempRanges[6];
public:
    DataThread();
    void run();
    void readData();
    void readTemp(char buff[]);
    void readVoltage(char buff[]);
    void contSerialReceive();

signals:
    void portOpen(bool);
    void sendVoltage(int,int,double);
    void sendTemp(int,int,double);
    void sendMaxVoltage(double);
    void sendMaxTemp(double);
    void sendMinVoltage(double);
    void sendMinTemp(double);
    void sendAveTemp(double);
    void sendAveVoltage(double);
    void sendGraphVoltage(int, int , int, int, int, int);
    void sendGraphTemp(int, int , int, int, int, int);
public slots:
    void serialReceive();
    void setPort(QString,int);
};
#endif // THREAD_H
