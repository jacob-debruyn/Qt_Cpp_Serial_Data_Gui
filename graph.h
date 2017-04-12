#ifndef GRAPH_H
#define GRAPH_H
#include <QWidget>
#include "qcustomplot.h"
class Graph
{
public:
    Graph();
    static void setUpGraphs2(QCustomPlot *, QCustomPlot *, QCPBars *, QCPBars *, QVector<double>) ;
};

#endif // GRAPH_H
