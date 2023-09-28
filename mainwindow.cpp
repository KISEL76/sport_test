#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // Конструктор
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->setTabEnabled(5, false);
    ui->tabWidget->setTabEnabled(6, false);
    ui->pushButton_finish->setVisible(false);
    ui->lcdNumber->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    setWindowTitle("Спортивный тест");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ticked()));
    counter = 90000;
}

MainWindow::~MainWindow() // Деструктор
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked() // Кнопка старта теста
{
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setTabEnabled(0, false);
    ui->lcdNumber->setVisible(true);
    ui->pushButton_finish->setVisible(true);

    mix();
    ui->radioButton_1_1->move(390, mas[0]);
    ui->radioButton_1_2->move(390, mas[1]);
    ui->radioButton_1_3->move(390, mas[2]);
    ui->radioButton_1_4->move(390, mas[3]);
    ui->pushButton_1_accept->setEnabled(false);
    timer->start(10);
}

void MainWindow::ticked() // Отсчет времени
{
    if (counter > 0){
        counter-=10;
        QTime time = QTime::fromMSecsSinceStartOfDay(counter);
        QString text = time.toString("HH:mm:ss.zzz");
        ui->lcdNumber->display(text);
    } else
        timer->stop();
}

void MainWindow::on_pushButton_finish_clicked() // Кнопка финиша теста
{
    ui->tabWidget->setTabEnabled(6, true);
    ui->tabWidget->setTabEnabled(0, false);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->setTabEnabled(5, false);
    ui->lcdNumber->setVisible(false);
    ui->pushButton_finish->setVisible(false);
}

void MainWindow::mix() // Функция перераспределения вариантов
{
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        int temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
}

// 1 вопрос
void MainWindow::on_radioButton_1_1_clicked()
{
    ui->pushButton_1_accept->setEnabled(true);
}

void MainWindow::on_radioButton_1_2_clicked()
{
    ui->pushButton_1_accept->setEnabled(true);
}

void MainWindow::on_radioButton_1_3_clicked()
{
    ui->pushButton_1_accept->setEnabled(true);
}

void MainWindow::on_radioButton_1_4_clicked()
{
    ui->pushButton_1_accept->setEnabled(true);
}

void MainWindow::on_pushButton_1_accept_clicked(
{
    if (ui->radioButton_1_1->isChecked()){
        ui->tableWidget->item(0,0)->setText("+");
        ui->tableWidget->item(0,0)->setBackground(Qt::green);
    }
    else{
        ui->tableWidget->item(0,0)->setText("-");
        ui->tableWidget->item(0,0)->setBackground(Qt::red);
    }

    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setTabEnabled(1, false);

}

//2 вопрос

//3 вопрос

//4 вопрос

//5 вопрос
