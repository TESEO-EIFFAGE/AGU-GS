#include "topdialog.h"
#include "ui_topdialog.h"
#include "mainwindow.h"
#include "hmi.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QRectF>

TopDialog::TopDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopDialog)
{
    ui->setupUi(this);
}


TopDialog::TopDialog(MavlinkProtocol *M, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TopDialog)
{
   MyM = M;
   qInfo() << "sono nel costruttore";
}

void TopDialog::UpdateWindow()
{
      QString s;
      s = QString::number(MyM->t.TimeStamp);
      QLabel *newlbl1= new QLabel(this);
      newlbl1->setText(s);
      newlbl1->setGeometry(50,10,30,80);
      /*      newlbl1->setGeometry((this->width() - newlbl1->sizeHint().width() / 2),
                         this->height() - newlbl1->sizeHint().height()/ 2,
                         newlbl1->sizeHint().width(), newlbl1->sizeHint().height());*/

      s = QString::number(MyM->t.TimeStampRIO);
      QLabel *newlbl2= new QLabel(this);
      newlbl2->setText(s);
      newlbl2->setGeometry(150,10,30,80);

      s = QString::number(MyM->t.Latitude);
      QLabel *newlbl3= new QLabel(this);
      newlbl3->setText(s);
      newlbl3->setGeometry(250,10,30,80);

      s = QString::number(MyM->t.Longitude);
      QLabel *newlbl4= new QLabel(this);
      newlbl4->setText(s);
      newlbl4->setGeometry(350,10,30,80);

      s = QString::number(MyM->t.GNSSAltitude);
      QLabel *newlbl5= new QLabel(this);
      newlbl5->setText(s);
      newlbl5->setGeometry(450,10,30,80);

      s = QString::number(MyM->t.AirSpeed_UVector);
      QLabel *newlbl6= new QLabel(this);
      newlbl6->setText(s);
      newlbl6->setGeometry(550,10,30,80);

      s = QString::number(MyM->t.AirSpeed_VVector);
      QLabel *newlbl7= new QLabel(this);
      newlbl7->setText(s);
      newlbl7->setGeometry(50,100,30,80);

      s = QString::number(MyM->t.AirSpeed_WVector);
      QLabel *newlbl8= new QLabel(this);
      newlbl8->setText(s);
      newlbl8->setGeometry(150,100,30,80);

      s = QString::number(MyM->t.AirTemperature);
      QLabel *newlbl9= new QLabel(this);
      newlbl9->setText(s);
      newlbl9->setGeometry(250,100,30,80);

      s = QString::number(MyM->t.AltitudeFromRadarAltimeter);
      QLabel *newlbl10= new QLabel(this);
      newlbl10->setText(s);
      newlbl10->setGeometry(350,100,30,80);

      s = QString::number(MyM->t.AltitudeFromPayloadAltimeter);
      QLabel *newlbl11= new QLabel(this);
      newlbl11->setText(s);
      newlbl11->setGeometry(450,100,30,80);

      s = QString::number(MyM->t.LinearVelocityHorizontal);
      QLabel *newlbl12= new QLabel(this);
      newlbl12->setText(s);
      newlbl12->setGeometry(550,100,30,80);

      s = QString::number(MyM->t.LinearVelocityVertical);
      QLabel *newlbl13= new QLabel(this);
      newlbl13->setText(s);
      newlbl13->setGeometry(50,200,30,80);

      s = QString::number(MyM->t.PositionAccuracy);
      QLabel *newlbl14= new QLabel(this);
      newlbl14->setText(s);
      newlbl14->setGeometry(150,200,30,80);

      s = QString::number(MyM->t.SpeedAccuracy);
      QLabel *newlbl15= new QLabel(this);
      newlbl15->setText(s);
      newlbl15->setGeometry(250,200,30,80);

      s = QString::number(MyM->t.LinearAccelerationX);
      QLabel *newlbl16= new QLabel(this);
      newlbl16->setText(s);
      newlbl16->setGeometry(350,200,30,80);

      s = QString::number(MyM->t.LinearAccelerationY);
      QLabel *newlbl17= new QLabel(this);
      newlbl17->setText(s);
      newlbl17->setGeometry(450,200,30,80);

      s = QString::number(MyM->t.LinearAccelerationZ);
      QLabel *newlbl18= new QLabel(this);
      newlbl18->setText(s);
      newlbl18->setGeometry(550,200,30,80);

      s = QString::number(MyM->t.ECEFVectorPositionX);
      QLabel *newlbl19= new QLabel(this);
      newlbl19->setText(s);
      newlbl19->setGeometry(50,300,30,80);

      s = QString::number(MyM->t.ECEFVectorPositionY);
      QLabel *newlbl20= new QLabel(this);
      newlbl20->setText(s);
      newlbl20->setGeometry(150,300,30,80);

      s = QString::number(MyM->t.ECEFVectorPositionZ);
      QLabel *newlbl21= new QLabel(this);
      newlbl21->setText(s);
      newlbl21->setGeometry(250,300,30,80);

      s = QString::number(MyM->t.ECEFVectorVelocityX);
      QLabel *newlbl22= new QLabel(this);
      newlbl22->setText(s);
      newlbl22->setGeometry(350,300,30,80);

      s = QString::number(MyM->t.ECEFVectorVelocityY);
      QLabel *newlbl23= new QLabel(this);
      newlbl23->setText(s);
      newlbl23->setGeometry(450,300,30,80);

      s = QString::number(MyM->t.ECEFVectorVelocityZ);
      QLabel *newlbl24= new QLabel(this);
      newlbl24->setText(s);
      newlbl24->setGeometry(550,300,30,80);

      s = QString::number(MyM->t.RollAngle);
      QLabel *newlbl25= new QLabel(this);
      newlbl25->setText(s);
      newlbl25->setGeometry(50,400,30,80);

      s = QString::number(MyM->t.PitchAngle);
      QLabel *newlbl26= new QLabel(this);
      newlbl26->setText(s);
      newlbl26->setGeometry(150,400,30,80);

      s = QString::number(MyM->t.YawAngle);
      QLabel *newlbl27= new QLabel(this);
      newlbl27->setText(s);
      newlbl27->setGeometry(250,400,30,80);

      s = QString::number(MyM->t.AgularRateRoll);
      QLabel *newlbl28= new QLabel(this);
      newlbl28->setText(s);
      newlbl28->setGeometry(350,400,30,80);

      s = QString::number(MyM->t.AgularRatePitch);
      QLabel *newlbl29= new QLabel(this);
      newlbl29->setText(s);
      newlbl29->setGeometry(450,400,30,80);

      s = QString::number(MyM->t.AgularRateYaw);
      QLabel *newlbl30= new QLabel(this);
      newlbl30->setText(s);
      newlbl30->setGeometry(550,400,30,80);

      s = QString::number(MyM->t.Quaternion0);
      QLabel *newlbl31= new QLabel(this);
      newlbl31->setText(s);
      newlbl31->setGeometry(50,500,30,80);

      s = QString::number(MyM->t.Quaternion1);
      QLabel *newlbl32= new QLabel(this);
      newlbl32->setText(s);
      newlbl32->setGeometry(150,500,30,80);

      s = QString::number(MyM->t.Quaternion2);
      QLabel *newlbl33= new QLabel(this);
      newlbl33->setText(s);
      newlbl33->setGeometry(250,500,30,80);

      s = QString::number(MyM->t.Quaternion3);
      QLabel *newlbl34= new QLabel(this);
      newlbl34->setText(s);
      newlbl34->setGeometry(350,500,30,80);

      s = QString::number(MyM->t.TelemetryStatusMask);
      QLabel *newlbl35= new QLabel(this);
      newlbl35->setText(s);
      newlbl35->setGeometry(450,500,30,80);

      s = QString::number(MyM->t.NumberOfGPSSatellite);
      QLabel *newlbl36= new QLabel(this);
      newlbl36->setText(s);
      newlbl36->setGeometry(550,500,30,80);

      qInfo() << "AgularRateYaw =!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << MyM->t.AgularRateYaw;

      this->show();
}

TopDialog::~TopDialog()
{
    delete ui;
}

