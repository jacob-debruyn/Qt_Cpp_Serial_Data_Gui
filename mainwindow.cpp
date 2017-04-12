#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{




    ui->setupUi(this);
    QPixmap pix( ":/new/res/logo.png" );
    ui->logo->setPixmap(pix);

    ticks << 1 << 2 << 3 << 4 << 5 << 6;
    voltageRange = new QCPBars(ui->chart->xAxis, ui->chart->yAxis);
    tempRange = new QCPBars(ui->chart_2->xAxis, ui->chart_2->yAxis);
    Graph::setUpGraphs2(ui->chart, ui->chart_2,voltageRange, tempRange, ticks);

    LayoutSetUp();
    tempSetUp();
    packCellSetUp();


}
void MainWindow::on_scan_ports_clicked()
{
    ui->port_list->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            ui->port_list->addItem(info.portName());
    }
   foreach (const qint32 &i, QSerialPortInfo::standardBaudRates()) {
            ui->baud_rate->addItem(QString::number(i));
   }
}

void MainWindow::on_connect_port_clicked()
{
    bool ok;
    QString port = ui->port_list->currentText();
    QString baud_rate = ui->baud_rate->currentText();
    int baud = baud_rate.toInt(&ok, 10);
    emit setPortSignal(port,baud);
}

void MainWindow::on_port_list_activated(int index)
{
    activateConnect[0]=true;
    if(activateConnect[1])ui->connect_port->setEnabled(true);
}

void MainWindow::on_baud_rate_activated(int index)
{
    activateConnect[1]=true;
    if(activateConnect[0])ui->connect_port->setEnabled(true);
}
void MainWindow::portStatus(bool status){
    if(status){
        ui->port_status->setText("Open");
        ui->port_status->setStyleSheet(styleSheet().append(QString("background-color : #00A88C;")) );
    }
    if(!status){
        ui->port_status->setText("Closed");
        ui->port_status->setStyleSheet("background-color : red;");
    }
}









void MainWindow::updateValue(int tabNum, int cellNum, double voltage)
{
    if(tabNum>=0&&tabNum<5){
        if(cellNum>=0&&cellNum<cellSize[tabNum]){
            cellArray[tabNum][cellNum]->setStatus('c',voltage);
        }
    }
}
void MainWindow::updateTempValue(int tabNum, int senorNum, double temp)
{
    qDebug()<< "test 1";
    if(tabNum>=0&&tabNum<5){
        if(senorNum>=0&&senorNum<tempSenorLimit[tabNum]){
            tempArray[tabNum][senorNum]->setStatus('t',temp);
        }
    }

}
void MainWindow::LayoutSetUp(){



    gridLayout[0]=ui->gridLayout;
    gridLayout[1]=ui->gridLayout_2;
    gridLayout[2]=ui->gridLayout_3;
    gridLayout[3]=ui->gridLayout_4;
    gridLayout[4]=ui->gridLayout_5;

    for(int i=0;i<5;i++){
        ui->tabWidget->setTabText(i, "Pack No: "+QString::number(i+1));
    }
    vertLayout[0]=ui->verticalLayout;
    vertLayout[1]=ui->verticalLayout_2;
    vertLayout[2]=ui->verticalLayout_3;
    vertLayout[3]=ui->verticalLayout_4;
    vertLayout[4]=ui->verticalLayout_5;


}
void MainWindow::tempSetUp(){
    for(int i=0;i<5;i++){

        for(int j=0;j<tempSenorLimit[i];j++){
            LabelBox *temp = new LabelBox();
            temp->setLabel("Temp Sensor: "+QString::number(j));
            vertLayout[i]->addWidget(temp);
            tempArray[i][j]=temp;


        }
        if(tempSenorLimit[i]==7){
                vertLayout[i]->insertSpacing(7,20);
                vertLayout[i]->insertSpacing(8,20);
                vertLayout[i]->insertSpacing(9,20);
                vertLayout[i]->insertSpacing(10,10);
        }
        if(tempSenorLimit[i]==6){
                vertLayout[i]->insertSpacing(6,20);
                vertLayout[i]->insertSpacing(7,20);
                vertLayout[i]->insertSpacing(8,20);
                vertLayout[i]->insertSpacing(9,20);
                vertLayout[i]->insertSpacing(10,20);
                vertLayout[i]->insertSpacing(11,10);


        }
    }

}
void MainWindow::packCellSetUp(){
    int packLimit=22;
    for(int i=0;i<5;i++){
        if(i==4)packLimit=28;
        int row=0;
        int level=0;
        for(int cellId=0;cellId<packLimit;cellId++){

            if(row==3)row=0;
            LabelBox *cell = new LabelBox();
            cell->setLabel("Cell No.: "+QString::number(cellId));

            cellArray[i][cellId]=cell;
            if(level>9){row++;level=0;}
            gridLayout[i]->addWidget(cell,level,row);
            level++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMaxVoltage(double voltage){
    ui->highVoltage->setText(QString::number(voltage));
}
void MainWindow::updateMaxTemp(double temp){
    ui->highTemp->setText(QString::number(temp));
}
void MainWindow::updateMinVoltage(double voltage){
    ui->lowVoltage->setText(QString::number(voltage));
}
void MainWindow::updateMinTemp(double temp){
    ui->lowTemp->setText(QString::number(temp));
}
void MainWindow::updateAveTemp(double temp){
    ui->aveTemp->setText(QString::number(temp));
}
void MainWindow::updateAveVoltage(double voltage){
    ui->aveVoltage->setText(QString::number(voltage));
}
void MainWindow::updateGraphVoltage(int, int , int, int, int, int){}
void MainWindow::updateGraphTemp(int, int , int, int, int, int){}
