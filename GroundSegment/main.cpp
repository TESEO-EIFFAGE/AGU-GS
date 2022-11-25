#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>
#include <QFontDatabase>
#include <iostream>

#include "gs_core.h"
#include "storage.h"
#include "hmi.h"
#include "src/radio_link/receiver/radio_link.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Setup fonts

    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Bold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Bold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Regular.ttf");
    QFontDatabase::addApplicationFont(":/content/fonts/RobotoMono-Medium.ttf");

    auto appFont = QFont("Roboto");
    appFont.setPixelSize(12);
    app.setFont(appFont);

    // Instantiate GS Core and expose some modules to QML

    QQmlApplicationEngine engine;
    auto gsCore = new GSCore(&app);
    auto hmi = gsCore->hmi();
    auto gpsData = gsCore->gnss();
    if(QCoreApplication::arguments().at(1) != "" && QCoreApplication::arguments().last() != "")
    {
        gsCore->setGNSSPort(QCoreApplication::arguments().at(1));
        gsCore->setRLPort(QCoreApplication::arguments().last());
    }
    engine.rootContext()->setContextProperty("hmi", hmi);
    engine.rootContext()->setContextProperty("gpsData", gpsData);

    // Load QML entry point

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
