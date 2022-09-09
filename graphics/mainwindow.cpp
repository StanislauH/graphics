#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.setBrush(col);
    p.drawPolygon(QPolygon()<<QPoint(100,40)<<QPoint(500,40)<<QPoint(500,100)<<QPoint(100,100));
    p.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    col = QColorDialog::getColor();
}
