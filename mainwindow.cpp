#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // make renderarea class
    // set layout
    QSizePolicy sizepolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizepolicy.setHorizontalStretch(0);
    sizepolicy.setVerticalStretch(0);
    sizepolicy.setHeightForWidth(ui->tableView->sizePolicy().hasHeightForWidth());
    ui->tableView->setSizePolicy(sizepolicy);

    QHBoxLayout* gridlayout = new QHBoxLayout(ui->centralwidget);
    gridlayout->addWidget(ui->tableView);
    gridlayout->addWidget(ui->groupBox);


}

MainWindow::~MainWindow()
{
    delete ui;
}
