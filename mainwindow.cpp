#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // make renderarea class
    // set layout
    //QSizePolicy sizepolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //sizepolicy.setHorizontalStretch(0);
    //sizepolicy.setVerticalStretch(0);
    //sizepolicy.setHeightForWidth(ui->tableView->sizePolicy().hasHeightForWidth());
    //ui->tableView->setSizePolicy(sizepolicy);

    QGridLayout *gridlayout = new QGridLayout(ui->centralwidget);
    gridlayout->addWidget(ui->tableWidget, 0, 0);
    gridlayout->addWidget(ui->groupBox, 0, 1);
    gridlayout->addWidget(ui->pushButton2, 1, 0, 1, 2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setItem(int row, int column) // self-made function (not auto-generated) 
{
    QTableWidgetItem *newItem = new QTableWidgetItem( QObject::tr("%1").arg((row+1)*(column+1)) );
    ui->tableWidget->setItem(row, column, newItem);
}

void MainWindow::updateTable()  // self-made function (not auto-generated) 
{
    int cnt = ui->spinBox->text().toInt();
    ui->tableWidget->setColumnCount(cnt);
    ui->tableWidget->setRowCount(cnt);
}

void MainWindow::on_pushButton2_clicked() // slot function, auto-generated
{
    for(int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        {
            setItem(i, j);
        }
    }

}

void MainWindow::on_spinBox_valueChanged(int arg1) // slot function, auto-generated
{
    updateTable();
}

