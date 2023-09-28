#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <time.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ticked();

    void on_pushButton_start_clicked();

    void on_pushButton_finish_clicked();

    void mix();


    void on_radioButton_1_1_clicked();

    void on_radioButton_1_2_clicked();

    void on_radioButton_1_3_clicked();

    void on_radioButton_1_4_clicked();

    void on_pushButton_1_accept_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int mas [4] = {150, 200, 250, 300};
    int counter;

};
#endif // MAINWINDOW_H
