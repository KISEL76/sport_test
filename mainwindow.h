#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <time.h>
#include <QMovie>
#include <QLabel>
#include <QSize>
#include <QVector>
#include <QRadioButton>


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

    void on_radioButton_2_1_clicked();

    void on_radioButton_2_2_clicked();

    void on_radioButton_2_3_clicked();

    void on_radioButton_2_4_clicked();

    void on_pushButton_2_accept_clicked();

    void clear_mem();

    void on_radioButton_3_1_clicked();

    void on_radioButton_3_2_clicked();

    void on_radioButton_3_3_clicked();

    void on_radioButton_3_4_clicked();

    void on_pushButton_3_accept_clicked();

    void on_radioButton_4_1_clicked();

    void on_radioButton_4_2_clicked();

    void on_radioButton_4_3_clicked();

    void on_radioButton_4_4_clicked();

    void on_pushButton_4_accept_clicked();

    void on_pushButton_5_accept_clicked();

    void on_radioButton_5_1_clicked();

    void on_radioButton_5_2_clicked();

    void on_radioButton_5_3_clicked();

    void on_radioButton_5_4_clicked();

    void processRadioButton(QRadioButton *radioButton,QRadioButton *radioButton_1, QRadioButton *radioButton_2, QRadioButton *radioButton_3, int i);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QMovie *start_gif;
    QLabel *start_label;
    int counter;
    int score;
    int mas [4] = {150, 200, 250, 300};
};
#endif // MAINWINDOW_H
