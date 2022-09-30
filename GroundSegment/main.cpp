#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>
#include <QFontDatabase>

#include "gs_core.h"
#include "storage.h"
#include "hmi.h"
#include "src/radio_link/receiver/radio_link.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Bold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Bold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Regular.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Medium.ttf");
    //QApplication a(argc, argv);
    //MainWindow w;

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

//    QSerialPort *Serial0 = new QSerialPort();

    // Serial0 PORTA CHE TRASMETTE

//    Serial0->setPortName("/dev/ttyUSB0");
//    Serial0->setParity(QSerialPort::NoParity);
//    Serial0->setBaudRate(QSerialPort::Baud115200);
//    Serial0->setStopBits(QSerialPort::OneStop);
//    Serial0->setFlowControl(QSerialPort::NoFlowControl);
//    Serial0->open(QIODevice::ReadWrite);


//    QProcess flight_segment_simulator;
//    flight_segment_simulator.setProgram("libs/F9P-Viewer/simulate_flying_vehicle/simulate_flying_vehicle");
//    flight_segment_simulator.start();

//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, [Serial0]() { Serial0->write("000000010100101001"); });
//    timer.start(500);
    /* PROVA */
    //Serial0->write(data);

     //w.show();

    QQmlApplicationEngine engine;
    auto gsCore = new GSCore(&app);
    auto radioLink = new RadioLink(&app);
    gsCore->setRadioLink(radioLink);
    auto hmi = gsCore->hmi();
    auto gpsData = gsCore->gpsData();

    engine.rootContext()->setContextProperty("hmi", hmi);
    engine.rootContext()->setContextProperty("gpsData", gpsData);

    engine.addImportPath("qrc:/imports");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
