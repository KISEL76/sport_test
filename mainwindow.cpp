#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // Конструктор
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Спортивный тест");

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

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ticked()));
    counter = 90000;
    score = 0;

    start_label = new QLabel(this);
    start_gif = new QMovie("/Users/kisel/Documents/Qt/Projects/test/pics/start-gravityfalls.gif");
    start_label->setMovie(start_gif);
    start_label->setScaledContents(true);
    start_label->move(500, 80);
    start_label->resize(340, 190);
    start_label->show();
    start_gif->start();

    QPixmap pic_1 ("/Users/kisel/Documents/Qt/Projects/test/pics/IMG_8318.JPG");
    ui->label->setPixmap(pic_1);
    QPixmap pic_2 ("/Users/kisel/Documents/Qt/Projects/test/pics/IMG_8319.JPG");
    ui->label_6->setPixmap(pic_2);
    QPixmap pic_3 ("/Users/kisel/Documents/Qt/Projects/test/pics/IMG_8320.JPG");
    ui->label_7->setPixmap(pic_3);
    QPixmap pic_4 ("/Users/kisel/Documents/Qt/Projects/test/pics/IMG_8321.JPG");
    ui->label_8->setPixmap(pic_4);
    QPixmap pic_5 ("/Users/kisel/Documents/Qt/Projects/test/pics/IMG_8322.JPG");
    ui->label_9->setPixmap(pic_5);
}

MainWindow::~MainWindow() // Деструктор
{
    clear_mem();
    delete ui;
}

void MainWindow::on_pushButton_start_clicked() // Кнопка старта теста
{
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setTabEnabled(0, false);
    ui->pushButton_finish->setVisible(true);
    ui->lcdNumber->setVisible(true);
    start_label->setVisible(false);

    mix();
    ui->radioButton_1_1->move(390, mas[0]);
    ui->radioButton_1_2->move(390, mas[1]);
    ui->radioButton_1_3->move(390, mas[2]);
    ui->radioButton_1_4->move(390, mas[3]);
    ui->pushButton_1_accept->setEnabled(false);
    timer->start(10);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 1;j++){
            if (ui->tableWidget->item(i,j) == nullptr){
                QTableWidgetItem *item = new QTableWidgetItem();
                ui->tableWidget->setItem(i,j, item);
            }
        }
    }

    for (int i = 0; i < 5;i++){
        ui->tableWidget->item(i,0)->setText("-");
        ui->tableWidget->item(i,0)->setBackground(Qt::red);
    }
}

void MainWindow::ticked() // Отсчет времени
{
    if (counter > 0){
        counter-=10;
        QTime time = QTime::fromMSecsSinceStartOfDay(counter);
        QString text = time.toString("HH:mm:ss.zzz");
        ui->lcdNumber->display(text);
    } else{
        timer->stop();
        ui->tabWidget->setTabEnabled(6, true);
        ui->tabWidget->setTabEnabled(0, false);
        ui->tabWidget->setTabEnabled(1, false);
        ui->tabWidget->setTabEnabled(2, false);
        ui->tabWidget->setTabEnabled(3, false);
        ui->tabWidget->setTabEnabled(4, false);
        ui->tabWidget->setTabEnabled(5, false);
        ui->pushButton_finish->setVisible(false);
    }
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
    ui->pushButton_finish->setVisible(false);

    timer->stop();

    if (score == 5){
        ui->label_result->setText("Результат: Прирожденный аналитик МАТЧ ТВ");
    }
    else if (score == 4){
        ui->label_result->setText("Результат: Спорт-ваше второе имя");
    }
    else if (score == 3){
        ui->label_result->setText("Результат: Любитель спорта");
    }
    else if (score < 3){
        ui->label_result->setText("Результат: Вы киберспортсмен");
    }
}

void MainWindow::mix() // Перераспределение вариантов
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

void MainWindow::clear_mem() // Очистка памяти
{
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 1; j++)
            if (ui->tableWidget->item(i,j) != nullptr){
                delete (ui->tableWidget->item(i,j));
            }
        }
}

void MainWindow::processRadioButton(QRadioButton *radioButton, QRadioButton *radioButton_1, QRadioButton *radioButton_2, QRadioButton *radioButton_3, int i) {
        if (radioButton->isChecked()) {
        ui->tableWidget->item(i,0)->setText("+");
            ui->tableWidget->item(i,0)->setBackground(Qt::green);
            score+=1;
        } else {
            ui->tableWidget->item(i,0)->setText("-");
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
        }
        ui->tabWidget->setTabEnabled(i+2, true);
        ui->tabWidget->setTabEnabled(i+1, false);

        mix();
        radioButton->move(390, mas[0]);
        radioButton_1->move(390, mas[1]);
        radioButton_2->move(390, mas[2]);
        radioButton_3->move(390, mas[3]);
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

void MainWindow::on_pushButton_1_accept_clicked()
{
    processRadioButton(ui->radioButton_1_1,ui->radioButton_1_2, ui->radioButton_1_3, ui->radioButton_1_4, 0);
    ui->pushButton_2_accept->setEnabled(false);
}

//2 вопрос

void MainWindow::on_radioButton_2_1_clicked()
{
    ui->pushButton_2_accept->setEnabled(true);
}

void MainWindow::on_radioButton_2_2_clicked()
{
    ui->pushButton_2_accept->setEnabled(true);
}

void MainWindow::on_radioButton_2_3_clicked()
{
    ui->pushButton_2_accept->setEnabled(true);
}

void MainWindow::on_radioButton_2_4_clicked()
{
    ui->pushButton_2_accept->setEnabled(true);
}

void MainWindow::on_pushButton_2_accept_clicked()
{
    processRadioButton(ui->radioButton_2_4,ui->radioButton_2_1, ui->radioButton_2_2, ui->radioButton_2_3, 1);
    ui->pushButton_3_accept->setEnabled(false);
}

//3 вопрос
void MainWindow::on_radioButton_3_1_clicked()
{
    ui->pushButton_3_accept->setEnabled(true);
}

void MainWindow::on_radioButton_3_2_clicked()
{
    ui->pushButton_3_accept->setEnabled(true);
}

void MainWindow::on_radioButton_3_3_clicked()
{
    ui->pushButton_3_accept->setEnabled(true);
}

void MainWindow::on_radioButton_3_4_clicked()
{
    ui->pushButton_3_accept->setEnabled(true);
}

void MainWindow::on_pushButton_3_accept_clicked()
{
    processRadioButton(ui->radioButton_3_3,ui->radioButton_3_1, ui->radioButton_3_2, ui->radioButton_3_4, 2);
    ui->pushButton_4_accept->setEnabled(false);
}

//4 Вопрос
void MainWindow::on_radioButton_4_1_clicked()
{
    ui->pushButton_4_accept->setEnabled(true);
}

void MainWindow::on_radioButton_4_2_clicked()
{
    ui->pushButton_4_accept->setEnabled(true);
}

void MainWindow::on_radioButton_4_3_clicked()
{
    ui->pushButton_4_accept->setEnabled(true);
}

void MainWindow::on_radioButton_4_4_clicked()
{
    ui->pushButton_4_accept->setEnabled(true);
}

void MainWindow::on_pushButton_4_accept_clicked()
{
    processRadioButton(ui->radioButton_4_2, ui->radioButton_4_3, ui->radioButton_4_1, ui->radioButton_4_4, 3);
    ui->pushButton_5_accept->setEnabled(false);
}

//5 вопрос
void MainWindow::on_radioButton_5_1_clicked()
{
    ui->pushButton_5_accept->setEnabled(true);
}

void MainWindow::on_radioButton_5_2_clicked()
{
    ui->pushButton_5_accept->setEnabled(true);
}

void MainWindow::on_radioButton_5_3_clicked()
{
    ui->pushButton_5_accept->setEnabled(true);
}

void MainWindow::on_radioButton_5_4_clicked()
{
    ui->pushButton_5_accept->setEnabled(true);
}

void MainWindow::on_pushButton_5_accept_clicked()
{
    processRadioButton(ui->radioButton_5_2,ui->radioButton_5_1, ui->radioButton_5_3, ui->radioButton_5_4, 4);
    ui->pushButton_finish->setVisible(false);
    timer->stop();

    if (score == 5){
            ui->label_result->setText("Результат: Прирожденный аналитик МАТЧ ТВ");
    }
    else if (score == 4){
            ui->label_result->setText("Результат: Спорт-ваше второе имя");
    }
    else if (score == 3){
            ui->label_result->setText("Результат: Любитель спорта");
    }
    else{
            ui->label_result->setText("Результат: Вы киберспортсмен");
    }
}


