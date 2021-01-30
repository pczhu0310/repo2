#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool gnBeginFlag=0;

    QSerialPort mSerial;
    QString mPortname;
    QString mBaudrate;

    QByteArray recvData;

    bool mGetPortinfoma();

public slots:
    void SerialPort_Readyread();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
