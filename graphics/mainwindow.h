#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*) override;

private slots:

    void on_pushButton_clicked();

    void on_pushButton1_clicked();

    void set_RGB();
    void set_SMYK();
    void set_HSL();
    void set_HSV();
    void set_XYZ();

    void on_pushButton_5_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
    QColor col;
};
#endif // MAINWINDOW_H
