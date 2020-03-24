#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	const QString urlStr = "http://ivi.bupt.edu.cn/";
	spider = new Spider(urlStr);

	spider->spiderStart();
	
}

MainWindow::~MainWindow()
{
    delete ui;
}
