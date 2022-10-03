#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(462,327);

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window,QColor(200,200,200));

    this->setPalette(darkPalette);
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

    connect(ui->lineE14,SIGNAL(textEdited(QString)),this, SLOT(set_XYZ()));
    connect(ui->lineE15,SIGNAL(textEdited(QString)),this, SLOT(set_XYZ()));
    connect(ui->lineE16,SIGNAL(textEdited(QString)),this, SLOT(set_XYZ()));

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
    col = Qt::black;
    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));
    update();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.setBrush(col);
    p.drawPolygon(QPolygon()<<QPoint(589,40)<<QPoint(731,40)<<QPoint(731,91)<<QPoint(589,91));
    p.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    col = QColorDialog::getColor();
    ui->line0->setText(0);
    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}

void MainWindow::on_pushButton1_clicked()
{
    setFixedSize(462,327);
    col.setRgb(0,0,0);
    ui->line0->setText(0);
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
    ui->lineE14->setText(0);
    ui->lineE15->setText(0);
    ui->lineE16->setText(0);
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

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}

void MainWindow::set_SMYK()
{
    col.setCmykF(ui->line7->text().toFloat(),ui->line8->text().toFloat(),ui->line9->text().toFloat(),ui->lineE10->text().toFloat());

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}

void MainWindow::set_HSL()
{
    col.setHslF(ui->lineE11->text().toFloat(),ui->lineE12->text().toFloat(),ui->lineE13->text().toFloat());

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}

void MainWindow::set_HSV()
{
    col.setHsvF(ui->lineE17->text().toFloat(),ui->lineE18->text().toFloat(),ui->lineE19->text().toFloat());

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}


void MainWindow::set_XYZ(){
    float X, Y, Z;

    X = ui->lineE14->text().toFloat();
    Y = ui->lineE15->text().toFloat();
    Z = ui->lineE16->text().toFloat();

    float var_X = X / 100;
    float var_Y = Y / 100;
    float var_Z = Z / 100;

    float var_R = var_X *  3.2406 + var_Y * -1.5372 + var_Z * -0.4986;
    float var_G = var_X * -0.9689 + var_Y *  1.8758 + var_Z *  0.0415;
    float var_B = var_X *  0.0557 + var_Y * -0.2040 + var_Z *  1.0570;

    if ( var_R > 0.0031308 ) var_R = 1.055 * ( pow(var_R , ( 1 / 2.4 )) ) - 0.055;
    else                     var_R = 12.92 * var_R;
    if ( var_G > 0.0031308 ) var_G = 1.055 * (pow(var_G , ( 1 / 2.4 ) )) - 0.055;
    else                     var_G = 12.92 * var_G;
    if ( var_B > 0.0031308 ) var_B = 1.055 * ( pow(var_B ,( 1 / 2.4 )) ) - 0.055;
    else                     var_B = 12.92 * var_B;

    float sR = var_R * 255;
    float sG = var_G * 255;
    float sB = var_B * 255;

    col.setRgb(sR,sG,sB);
    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));
}

void MainWindow::on_pushButton_5_clicked()
{
    setFixedSize(893,327);
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

void MainWindow::on_pushButton_17_clicked()
{
    setFixedSize(893,327);
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
    setFixedSize(893,327);
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
    setFixedSize(893,327);
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

void MainWindow::on_pushButton_18_clicked()
{
    setFixedSize(893,327);
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
    setFixedSize(893,327);
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

void MainWindow::on_pushButton_10_clicked()
{
    setFixedSize(893,327);
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
    setFixedSize(893,327);
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


void MainWindow::on_pushButton_19_clicked()
{
    setFixedSize(893,327);
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

void MainWindow::on_pushButton_2_clicked()
{
    col.setNamedColor(ui->line0->text());
    ui->line1->setText(QString::number(col.red()));
    ui->line2->setText(QString::number(col.green()));
    ui->line3->setText(QString::number(col.blue()));

    ui->line7->setText(QString::number(col.cyanF(),'f',3));
    ui->line8->setText(QString::number(col.magentaF(),'f',3));
    ui->line9->setText(QString::number(col.yellowF(),'f',3));
    ui->lineE10->setText(QString::number(col.blackF(),'f',3));

    ui->lineE11->setText(QString::number(col.hueF(),'f',3));
    ui->lineE12->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE13->setText(QString::number(col.lightnessF(),'f',3));

    ui->lineE17->setText(QString::number(col.hueF(),'f',3));
    ui->lineE18->setText(QString::number(col.saturationF(),'f',3));
    ui->lineE19->setText(QString::number(col.valueF(),'f',3));

    float sR = col.red();
    float sG = col.green();
    float sB = col.blue();
    float var_R = ( sR / 255 );
    float var_G = ( sG / 255 );
    float var_B = ( sB / 255 );

    if ( var_R > 0.04045 ) var_R = pow((( var_R + 0.055 ) / 1.055 ) , 2.4);
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow((( var_G + 0.055 ) / 1.055 ) , 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow((( var_B + 0.055 ) / 1.055 ),  2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    float X, Y, Z;
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

    ui->lineE14->setText(QString::number(X,'f',3));
    ui->lineE15->setText(QString::number(Y,'f',3));
    ui->lineE16->setText(QString::number(Z,'f',3));

    update();
}
