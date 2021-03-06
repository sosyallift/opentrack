#pragma once

#include "thread.hpp"
#include "api/plugin-support.hpp"
#include "ftnoir_tracker_hat_settings.h"
#include "ftnoir_arduino_type.h"

#include <QObject>
#include <QPalette>
#include <QtGui>
#include <QByteArray>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSettings>

#define VER_FILEVERSION_STR         "Version 2.1.1"

class hatire : public QObject, public ITracker
{
    Q_OBJECT

public:
    hatire();
    ~hatire();

    void start_tracker(QFrame*);
    void data(double *data);
    //void center();
    //bool notifyZeroed();
    void reset();
    void get_info( int *tps );
    void serial_info();
    void send_serial_command(const QByteArray& x);

    hatire_thread t;
private:
    TArduinoData ArduinoData, HAT;
    QByteArray Begin;
    QByteArray End;

    TrackerSettings s;

    int frame_cnt;

    volatile int CptError;

    static inline QByteArray to_latin1(const QString& str) { return str.toLatin1(); }
};

class TrackerDll : public Metadata
{
    QString name() { return QString("Hatire Arduino"); }
    QIcon icon() { return QIcon(":/images/hat.png"); }
};
