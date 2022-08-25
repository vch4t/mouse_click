#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <QString>
#include <QIntValidator>
#include <QKeyEvent>
#include <QButtonGroup>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void click_click();
    void click_count();
private slots:
    void on_lineEdit_editingFinished();
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    uint times;
    uint save_counting,counting;
    QButtonGroup m_btnGroup1;
};
#endif // MAINWINDOW_H
