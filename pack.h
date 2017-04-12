#ifndef PACK_H
#define PACK_H

#include <QTabWidget>

namespace Ui {
class Pack;
}

class Pack : public QTabWidget
{
    Q_OBJECT

public:
    explicit Pack(QWidget *parent = 0);
    ~Pack();

private:
    Ui::Pack *ui;
};

#endif // PACK_H
