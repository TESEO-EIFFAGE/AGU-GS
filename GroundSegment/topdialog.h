#ifndef TOPDIALOG_H
#define TOPDIALOG_H

#include <QDialog>
#include "mavlinkprotocol.h"

namespace Ui {
class TopDialog;
}

class TopDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TopDialog(QWidget *parent = nullptr);
    TopDialog(MavlinkProtocol *M, QWidget *parent = nullptr);
    //TopDialog(MavlinkProtocol *M);
    ~TopDialog();

    MavlinkProtocol *MyM;
public slots:
    void UpdateWindow();
private slots:

signals:
    void aaaaa(Ui::TopDialog *ui);
private:
    Ui::TopDialog *ui;
};

#endif // TOPDIALOG_H
