#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->line1,SIGNAL(textEdited(QString)),this, SLOT(set_RGB()));
    connect(ui->line2,SIGNAL(textEdited(QString)),this, SLOT(set_RGB()));
    connect(ui->line3,SIGNAL(textEdited(QString)),this, SLOT(set_RGB()));

    connect(ui->line7,SIGNAL(textEdited(QString)),this, SLOT(set_SMYK()));
    connect(ui->line8,SIGNAL(textEdited(QString)),this, SLOT(set_SMYK()));
    connect(ui->line9,SIGNAL(textEdited(QString)),this, SLOT(set_SMYK()));
    connect(ui->lineE10,SIGNAL(textEdited(QString)),this, SLOT(set_SMYK()));

    connect(ui->lineE11,SIGNAL(textEdited(QString)),this, SLOT(set_HSL()));
    connect(ui->lineE12,SIGNAL(textEdited(QString)),this, SLOT(set_HSL()));
    connect(ui->lineE13,SIGNAL(textEdited(QString)),this, SLOT(set_HSL()));

    connect(ui->lineE17,SIGNAL(textEdited(QString)),this, SLOT(set_HSV()));
    connect(ui->lineE18,SIGNAL(textEdited(QString)),this, SLOT(set_HSV()));
    connect(ui->lineE19,SIGNAL(textEdited(QString)),this, SLOT(set_HSV()));

    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();

    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->pushButton1->hide();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.setBrush(col);
    p.drawPolygon(QPolygon()<<QPoint(40,50)<<QPoint(376,50)<<QPoint(376,150)<<QPoint(40,150));
    p.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    col = QColorDialog::getColor();
    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->line7->setText(QString::number(col.cyanF()));
    ui->line8->setText(QString::number(col.magentaF()));
    ui->line9->setText(QString::number(col.yellowF()));
    ui->lineE10->setText(QString::number(col.blackF()));

    ui->lineE11->setText(QString::number(col.hueF()));
    ui->lineE12->setText(QString::number(col.saturationF()));
    ui->lineE13->setText(QString::number(col.lightnessF()));

    ui->lineE17->setText(QString::number(col.hueF()));
    ui->lineE18->setText(QString::number(col.saturationF()));
    ui->lineE19->setText(QString::number(col.valueF()));

}

void MainWindow::on_pushButton1_clicked()
{
    col.setRgb(0,0,0);
    ui->line1->setText(0);
    ui->line2->setText(0);
    ui->line3->setText(0);
    ui->line7->setText(0);
    ui->line8->setText(0);
    ui->line9->setText(0);
    ui->lineE10->setText(0);
    ui->lineE11->setText(0);
    ui->lineE12->setText(0);
    ui->lineE13->setText(0);
    ui->lineE17->setText(0);
    ui->lineE18->setText(0);
    ui->lineE19->setText(0);

    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();

    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->pushButton1->hide();
    update();
}

void MainWindow::set_RGB()
{
    col.setRgb(ui->line1->text().toInt(),ui->line2->text().toInt(),ui->line3->text().toInt());

    ui->line7->setText(QString::number(col.cyanF()));
    ui->line8->setText(QString::number(col.magentaF()));
    ui->line9->setText(QString::number(col.yellowF()));
    ui->lineE10->setText(QString::number(col.blackF()));

    ui->lineE11->setText(QString::number(col.hueF()));
    ui->lineE12->setText(QString::number(col.saturationF()));
    ui->lineE13->setText(QString::number(col.lightnessF()));

    ui->lineE17->setText(QString::number(col.hueF()));
    ui->lineE18->setText(QString::number(col.saturationF()));
    ui->lineE19->setText(QString::number(col.valueF()));

    update();
}

void MainWindow::set_SMYK()
{
    col.setCmykF(ui->line7->text().toFloat(),ui->line8->text().toFloat(),ui->line9->text().toFloat(),ui->line3->text().toFloat());

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE11->setText(QString::number(col.hueF()));
    ui->lineE12->setText(QString::number(col.saturationF()));
    ui->lineE13->setText(QString::number(col.lightnessF()));

    ui->lineE17->setText(QString::number(col.hueF()));
    ui->lineE18->setText(QString::number(col.saturationF()));
    ui->lineE19->setText(QString::number(col.valueF()));

    update();
}

void MainWindow::set_HSL()
{
    col.setHslF(ui->lineE11->text().toFloat(),ui->lineE12->text().toFloat(),ui->lineE13->text().toFloat());

    ui->line7->setText(QString::number(col.cyanF()));
    ui->line8->setText(QString::number(col.magentaF()));
    ui->line9->setText(QString::number(col.yellowF()));
    ui->lineE10->setText(QString::number(col.blackF()));

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE17->setText(QString::number(col.hueF()));
    ui->lineE18->setText(QString::number(col.saturationF()));
    ui->lineE19->setText(QString::number(col.valueF()));

    update();
}

void MainWindow::set_HSV()
{
    col.setHsvF(ui->lineE17->text().toFloat(),ui->lineE18->text().toFloat(),ui->lineE19->text().toFloat());

    ui->line7->setText(QString::number(col.cyanF()));
    ui->line8->setText(QString::number(col.magentaF()));
    ui->line9->setText(QString::number(col.yellowF()));
    ui->lineE10->setText(QString::number(col.blackF()));

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE11->setText(QString::number(col.hueF()));
    ui->lineE12->setText(QString::number(col.saturationF()));
    ui->lineE13->setText(QString::number(col.lightnessF()));

    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->label1->show(); ui->label2->show(); ui->label3->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE11->show(); ui->lineE12->show(); ui->lineE13->show();
    ui->label4->show(); ui->label1->show(); ui->label3->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->label1->show(); ui->label5->show(); ui->label2->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->label1->show(); ui->label2->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->label2->show(); ui->label3->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE11->show(); ui->lineE12->show(); ui->lineE13->show();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->label1->show(); ui->label3->show(); ui->label4->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->label1->show(); ui->label3->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->label1->show(); ui->label5->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->label2->show(); ui->label5->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->label1->show(); ui->label3->show(); ui->label2->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->lineE11->show(); ui->lineE12->show(); ui->lineE13->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->label2->show(); ui->label4->show(); ui->label5->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->label1->show(); ui->label5->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->label1->show(); ui->label3->show(); ui->label5->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->label2->show(); ui->label3->show(); ui->label5->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE17->show(); ui->lineE18->show(); ui->lineE19->show();
    ui->label1->show(); ui->label3->show(); ui->label6->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE11->show(); ui->lineE12->show(); ui->lineE13->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->label3->show(); ui->label4->show(); ui->label5->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line4->show(); ui->line5->show(); ui->line6->show();
    ui->lineE11->show(); ui->lineE12->show(); ui->lineE13->show();
    ui->label1->show(); ui->label2->show(); ui->label4->show();
    ui->pushButton1->show();
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->line1->hide(); ui->line2->hide(); ui->line3->hide();
    ui->line4->hide(); ui->line5->hide(); ui->line6->hide();
    ui->line7->hide(); ui->line8->hide(); ui->line9->hide(); ui->lineE10->hide();
    ui->lineE11->hide(); ui->lineE12->hide(); ui->lineE13->hide();
    ui->lineE14->hide(); ui->lineE15->hide(); ui->lineE16->hide();
    ui->lineE17->hide(); ui->lineE18->hide(); ui->lineE19->hide();
    ui->label1->hide(); ui->label2->hide(); ui->label3->hide();
    ui->label4->hide(); ui->label5->hide(); ui->label6->hide();
    ui->line1->show(); ui->line2->show(); ui->line3->show();
    ui->line7->show(); ui->line8->show(); ui->line9->show(); ui->lineE10->show();
    ui->lineE14->show(); ui->lineE15->show(); ui->lineE16->show();
    ui->label1->show();ui->label3->show();ui->label5->show();
    ui->pushButton1->show();
}
