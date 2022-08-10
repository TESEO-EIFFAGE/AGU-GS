#ifndef HMI_H
#define HMI_H
//#include "mainwindow.h"
#include "mavlinkprotocol.h"
#include "ui_mainwindow.h"
#include <QObject>
#include "topdialog.h"

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);
    HMI(Ui::MainWindow *ui);

    Ui::MainWindow myui;
    TopDialog TopDialogWindow;

public slots:
    void showData(Telemetry *t);
    void showDataSystemStatus (SystemStatusPack *s);

signals:
    void clicked_HMI();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

};

#endif // HMI_H
