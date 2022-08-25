#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    times=100;
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    setWindowTitle(QString::fromLocal8Bit("似乎是个连点器"));
    ui->lineEdit->setValidator(new QIntValidator(0, 1000, this));
    ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit("0~9999，默认100"));
    ui->spinBox->setRange(0,9999);
    m_btnGroup1.addButton(ui->mugen,0);
    m_btnGroup1.addButton(ui->newNumber,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_click()
{
    while (1)
        {
            if (GetAsyncKeyState(VK_LCONTROL))//按下空格，开始执行
            {
                while (1)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//当前位置点击一次鼠标
                    Sleep(times);//每0.5秒点击一次
                    if (GetAsyncKeyState(VK_RCONTROL))break;
                    if (GetAsyncKeyState(VK_ESCAPE))return; //按esc退出
                }
            }
    }
}

void MainWindow::click_count()
{
    while (1)
        {
            if (GetAsyncKeyState(VK_LCONTROL))//按下空格，开始执行
            {
                while (1)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//当前位置点击一次鼠标
                    Sleep(times);//每0.5秒点击一次
                    if (GetAsyncKeyState(VK_RCONTROL))break;
                    if (GetAsyncKeyState(VK_ESCAPE))return;
                    if(!--counting)
                    {
                        counting=save_counting;
                        return;
                    }
                }
            }
    }
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString str=ui->lineEdit->text();
    times=str.toUInt();
    qDebug()<<times;
}


void MainWindow::on_pushButton_clicked()
{
    if(m_btnGroup1.checkedId() == 0)
    {
        click_click();
    }
    else
    {
        click_count();
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    save_counting=counting=arg1;
}

