#include "mainwindow.h"
#include "topdialog.h"
#include <QApplication>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>
#include "mavlinkprotocol.h"
#include "storage.h"
#include <thread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QByteArray data  = "FD77000000FFAA000011"
                       "000102030405060708090A0B0C0D0E0F"   /*  P  */
                       "000102030405060708090A0B0C0D0E0F"   /*  A  */
                       "000102030405060708090A0B0C0D0E0F"   /*  Y  */
                       "000102030405060708090A0B0C0D0E0F"   /*  L  */
                       "000102030405060708090A0B0C0D0E0F"   /*  O  */
                       "000102030405060708090A0B0C0D0E0F"   /*  A  */
                       "000102030405060708090A0B0C0D0E0F"   /*  D  */
                       "00010203040506"
                       "59E7";

//    QByteArray data  = "FD010000000101010101010D3D";

    QSerialPort *Serial0 = new QSerialPort();

    // Serial0 PORTA CHE TRASMETTE

    Serial0->setPortName("/dev/ttyUSB0");
    Serial0->setParity(QSerialPort::NoParity);
    Serial0->setBaudRate(QSerialPort::Baud115200);
    Serial0->setStopBits(QSerialPort::OneStop);
    Serial0->setFlowControl(QSerialPort::NoFlowControl);
    Serial0->open(QIODevice::ReadWrite);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [Serial0]() { Serial0->write("000000010100101001"); });
    timer.start(500);

    //Serial0->write(data);

     w.show();

     return a.exec();
}
