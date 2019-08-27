#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QApplication>
#include<QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("test"));
    moveToCenter(parent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveToCenter(QWidget*parent)
{
    int centerX = 0;
    int centerY = 0;
    if(parent != NULL){
        QPoint center = parent->mapToGlobal(QPoint(parent->width()/2,parent->height()/2));
        centerX = center.x();
        centerY = center.y();
    }else{
        centerX = QApplication::desktop()->width()/2;
        centerY = QApplication::desktop()->height()/2;
    }
    int x = centerX - this->width()/2;
    int y = centerY - this->height()/2;
    this->move(x,y);
}
