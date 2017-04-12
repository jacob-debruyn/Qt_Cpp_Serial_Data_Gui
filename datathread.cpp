#include "datathread.h"
#include <QtCore>
#include <stdlib.h>
DataThread::DataThread()
{
}
void DataThread::run()
{
    //this is where reading data occurs





}
void DataThread::serialReceive(){


     char buff[100];

         if (serialPort.canReadLine()){



              serialPort.readLine(buff,100);
              if(buff[0]=='T'){
                  qDebug()<< "test";
                 readTemp(buff);
              }//'T' FOUND
              if(buff[0]=='C'){
                 readVoltage(buff);
              }//'C' FOUND
         }



   // }
}
void DataThread::setPort(QString port, int baud_rate){
    maxVoltage=0;
    minVoltage=10000;
    minTemp=100000;
    maxTemp=0;
    tempCounter=0;
    cellCounter=0;
    serialPort.close();
    serialPort.setPortName(port);
    serialPort.setBaudRate(baud_rate);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setStopBits(QSerialPort::OneStop);
    if (serialPort.open(QIODevice::ReadOnly)){
        connect(&serialPort, SIGNAL(readyRead()), this, SLOT(serialReceive()));
        emit portOpen(true);
    }else emit portOpen(false);
}
void DataThread::contSerialReceive(){
    char buff[100];
    while(true){
        if (serialPort.canReadLine()){
            qDebug()<< "test 1";
             serialPort.readLine(buff,100);

             /*if(buff[0]=='T'){
                readTemp(buff);
             }//'T' FOUND*/
             if(buff[0]=='C'){
                 qDebug()<< "test 2";
                readTemp(buff);
             }//'C' FOUND
        }
    }
}

void DataThread::readTemp(char buff[]){
    int dataArray[2];
    int j=0;
    //qDebug()<< "t found";
    //int dataInt = std::stoi(buff);
    buff[0]=' ';
    QString s = QString::fromUtf8(buff);

    QRegExp rx("(\\ |\\n)"); //RegEx for ' ' or ',' or '.' or ':' or '\n'
    QStringList query = s.split(rx);
    for(int i=0;i<query.size();i++){
        if(QString::compare(query[i], "", Qt::CaseInsensitive)&&j<2){
            dataArray[j]=query[i].toInt();
            j++;

        }

    }
    qDebug()<< dataArray[0];

    double temp = ((double)dataArray[1]/100)-273;
    if(dataArray[0]<6){emit sendTemp(0,dataArray[0],temp);}
    else if(dataArray[0]<13){emit sendTemp(1,(dataArray[0]-6),temp);}
    else if(dataArray[0]<19){emit sendTemp(2,(dataArray[0]-13),temp);}
    else if(dataArray[0]<26){emit sendTemp(3,(dataArray[0]-19),temp);}
    else if(dataArray[0]<35){emit sendTemp(4,(dataArray[0]-26),temp);}
}
void DataThread::readVoltage(char buff[]){

    cellCounter++;
    int dataArray[2];
    int j=0;
    buff[0]=' ';
    QString s = QString::fromUtf8(buff);

    QRegExp rx("(\\ |\\n)"); //RegEx for ' ' or ',' or '.' or ':' or '\n'
    QStringList query = s.split(rx);
    for(int i=0;i<query.size();i++){
        if(QString::compare(query[i], "", Qt::CaseInsensitive)&&j<2){
            dataArray[j]=query[i].toInt();
            j++;

        }

    }
    double voltage = (double)dataArray[1]/10000;
    if(dataArray[0]<22){emit sendVoltage(0,dataArray[0],voltage);}
    else if(dataArray[0]<44){emit sendVoltage(1,(dataArray[0]-22),voltage);}
    else if(dataArray[0]<66){emit sendVoltage(2,(dataArray[0]-44),voltage);}
    else if(dataArray[0]<88){emit sendVoltage(3,(dataArray[0]-66),voltage);}
    else if(dataArray[0]<116){emit sendVoltage(4,(dataArray[0]-88),voltage);}


    if(voltage>maxVoltage){
        maxVoltage=voltage;
        emit sendMaxVoltage(maxVoltage);
        qDebug()<<"test 666";
    }
    if(voltage<minVoltage){
        minVoltage=voltage;
        emit sendMinVoltage(minVoltage);
    }

    if(voltage<3)voltageRanges[0]++;
    else if(voltage<3.2)voltageRanges[1]++;
    else if(voltage<3.4)voltageRanges[2]++;
    else if(voltage<3.6)voltageRanges[3]++;
    else if(voltage<3.8)voltageRanges[4]++;
    else if(voltage>3.8)voltageRanges[5]++;
    cellTotal+=voltage;
    if(cellCounter==116){
        aveVoltage = cellTotal/116;
        emit sendAveVoltage(aveVoltage);
        emit sendGraphVoltage(voltageRanges[0],voltageRanges[1],voltageRanges[2],voltageRanges[3],voltageRanges[4],voltageRanges[5]);
        maxVoltage=0;
        maxTemp=0;

        minVoltage=10000;
        minTemp=100000;

        tempCounter=0;
        cellCounter=0;
    }
}


