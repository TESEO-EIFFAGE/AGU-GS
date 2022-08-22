#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "mavlinkprotocol.h"
#include "storage.h"
#include "hmi.h"
#include "topdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class HMIController : public QMainWindow
{
    Q_OBJECT

public:
    HMIController(QWidget *parent = nullptr);
    ~HMIController();

    QSerialPort *Serial1;
    uint64_t TimeStampToHMI;
    qint8 Counter;

signals:
    void DataIsRead (QByteArray data);
    void work_is_down(void);
    void updateTopDiagLog(void);


public slots:
    void ReadData(void);
    void WriteHartBeat();

private slots:
    //void on_pushButton_clicked(Ui::TopDialog *ui);
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    TopDialog *TopDialogWindow;

};
#endif // MAINWINDOW_H
