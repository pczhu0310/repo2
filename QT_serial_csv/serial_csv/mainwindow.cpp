#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*********写csv********/
    ofstream outFile;
    outFile.open("data.csv", ios::out); // 打开模式可省略
    outFile << "name" << ',' << "age" << ',' << "hobby" << endl;
    outFile << "Mike" << ',' << 18 << ',' << "paiting" << endl;
    outFile << "Tom" << ',' << 25 << ',' << "football" << endl;
    outFile << "Jack" << ',' << 20 << ',' << "music" << endl;
    outFile.close();
    /*********写csv********/


    /*********获取支持串口号********/
    QList<QSerialPortInfo> serialPortinfo = QSerialPortInfo::availablePorts();
    int count = serialPortinfo.count();
    for(int i = 0; i<count; i++)
    {
       ui->SPUPORT->addItem(serialPortinfo.at(i).portName());
    }
    /*********获取支持串口号********/
    /*********获取支持波特率********/
    QList<qint32> serialBaudRatesinfo=QSerialPortInfo::standardBaudRates();

    for(QList<qint32>::const_iterator it=serialBaudRatesinfo.begin();it!=serialBaudRatesinfo.end();it++)
    {
        ui->SPUBAUD->addItem(QString::number(*it));
    }
    /*********获取支持波特率********/

    connect(ui->BEGINBUTTON,&QPushButton::clicked,[=]()
    {
        gnBeginFlag = !gnBeginFlag;

        if(gnBeginFlag == 0)
        {
            ui->BEGINBUTTON->setText("开始");
            mSerial.close();
            ui->SPUPORT->setEnabled(true);
            ui->SPUBAUD->setEnabled(true);
        }
        else
        {
            if(!mGetPortinfoma())
            {
                gnBeginFlag=0;
            }
            else
            {
                ui->BEGINBUTTON->setText("停止");
                mGetPortinfoma();
                ui->SPUPORT->setEnabled(false);
                ui->SPUBAUD->setEnabled(false);
            }
        }
    });

    connect(&mSerial,SIGNAL(readyRead()),this,SLOT(SerialPort_Readyread()));
}

bool  MainWindow::mGetPortinfoma()
{
    mPortname = ui->SPUPORT->currentText();
    mBaudrate = ui->SPUBAUD->currentText();

    mSerial.setPortName(mPortname);

    if(mBaudrate == "9600")
    {
        mSerial.setBaudRate(QSerialPort::Baud9600);
    }
    else if(mBaudrate == "19200")
    {
        mSerial.setBaudRate(QSerialPort::Baud19200);
    }
    else
    {
        mSerial.setBaudRate(QSerialPort::Baud115200);
    }
    /****默认*****/
    mSerial.setPortName("COM11");
    mSerial.setBaudRate(QSerialPort::Baud115200);
    /****默认*****/
    return mSerial.open(QSerialPort::ReadWrite);
}


void MainWindow::SerialPort_Readyread()
{
    recvData = mSerial.readAll();

    ui->plainTextEdit->insertPlainText(recvData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

