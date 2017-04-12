#ifndef LABELBOX_H
#define LABELBOX_H

#include <QWidget>

namespace Ui {
class LabelBox;
}

class LabelBox : public QWidget
{
    Q_OBJECT

public:
    explicit LabelBox(QWidget *parent = 0);
    void setLabel(QString);
    void setStatus(char,double);
    ~LabelBox();

private:
    Ui::LabelBox *ui;
};

#endif // LABELBOX_H
