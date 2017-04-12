#ifndef CELLBLOCK_H
#define CELLBLOCK_H

#include <QGroupBox>

namespace Ui {
class CellBlock;
}

class CellBlock : public QGroupBox
{
    Q_OBJECT

public:
    explicit CellBlock(QWidget *parent = 0);
    void changeTitle(QString X){setTitle(X);}
    void setVoltage(double v);
    ~CellBlock();

private:
    Ui::CellBlock *ui;
};

#endif // CELLBLOCK_H
