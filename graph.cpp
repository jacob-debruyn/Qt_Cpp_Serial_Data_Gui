#include "graph.h"

Graph::Graph()
{

}
void Graph::setUpGraphs2(QCustomPlot *chart, QCustomPlot *chart_2,QCPBars *voltageRange,QCPBars *tempRange,QVector<double> ticks)
{

    chart->setBackground(QColor(240,240,240));

    voltageRange->setAntialiased(false);
    voltageRange->setStackingGap(1);;
    voltageRange->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    voltageRange->setBrush(QColor(0, 168, 140));
    QVector<QString> labels;
    labels << "<3" << "3.0-3.2" << "3.2-3.4" << "3.4-3.6" << "3.6-3.8" << ">3.8";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    chart->xAxis->setTicker(textTicker);
    chart->xAxis->setLabel("Votlage ranges");
    chart->xAxis->setRange(0, 6.5);
    chart->yAxis->setLabel("No. of cells in range");
    chart->yAxis->setRange(0, 116);
    chart->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);





    chart_2->setBackground(QColor(240,240,240));
    tempRange->setAntialiased(false);
    tempRange->setStackingGap(1);;
    tempRange->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    tempRange->setBrush(QColor(0, 168, 140));
    QSharedPointer<QCPAxisTickerText> textTickerT(new QCPAxisTickerText);
    labels.clear();
    labels << "<10" << "10-20" << "20-30" << "30-40" << "40-50" << ">50";
    textTickerT->addTicks(ticks, labels);
    chart_2->xAxis->setTicker(textTickerT);
    chart_2->xAxis->setLabel("Temperature ranges");
    chart_2->xAxis->setRange(0, 6.5);
    chart_2->yAxis->setLabel("No. of cells in range");
    chart_2->yAxis->setRange(0, 36);
    chart_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
}
