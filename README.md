# Tasks

## Task 1. Multiplication table 

Examine the project multiplication_table.pro to create a new Qt Widgets project. 
The task is to output a multimplication table on the form using a tableWidget. 

### Designer

Modify the interface of your project using Qt Designer.

Examine the form.jpeg picture. It shows the arrangement of the widgets.

![form](https://github.com/marymex/QT_layouts_buttons_tableWidget/blob/master/form.jpg)

Add a button, a tableWidget, a groupBox on your form.

Inside the groupBox add a label, a spinButton and a verticalSpacer.

Set the verticalLayout for the groupbox: right mouth click -> Layout (Компоновка) -> Layout vertically (Скомпоновать по вертикали).


### Slots and signals

In QT some widgets send signals when the user is interracting with the form and some other widgets catch those signals.
To catch a signal send by one widget, another widget has a function called "slot function". Now we are going to set some slot functions for some widgets. 

Right-mouth-click on pushButton -> go to slot -> clicked(). See go_to_slot___clicked.jpeg. 

![go_to_slot___clicked](https://github.com/marymex/QT_layouts_buttons_tableWidget/blob/master/go_to_slot___clicked.jpeg)

Those actions auto-generate some code in mainwindow.cpp and mainwindow.h. Namely, they add a slot function which will be run when the user clicks on the button. In mainwindow.h we can find the declaration of a new function: 

```sh
void on_pushButton_clicked();
```

In mainwindow.cpp (NOTE, this file is NOT mainwindow.h) we see the body of the function:

```sh
void MainWindow::on_pushButton_clicked()
{

}
```

Inside the body of the function we write code which will be executed when we click on the button.

Simularly, generate a slot-function for the spinBox: Right-mouth-click on spinBox -> go to slot -> valuechanged().  

The idea of the task is that when the user changes the value inside spinBox to n, tableWidget displays an empty square table with n rows and n columns.   
For this purpose we need to take the number inside spinBox and set the number of rows and columns inside the table:  

```sh
void MainWindow::updateTable()
{
    int cnt = ui->spinBox->text().toInt();
    ui->tableWidget->setColumnCount(cnt);
    ui->tableWidget->setRowCount(cnt);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    updateTable();
}
```
Here we use a new function updateTable() which was NOT auto-generated. That's why we need to add the declaration of this function in mainwindow.h:

```sh

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateTable(); // NOTE this one

private slots:
    void on_pushButton_clicked();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

```

In the project the function updateTable is run for this purpose. Note that every time when you code a new function in mainwindow.cpp and declare it as a member of MainWindow class (you do that by writing MainWindow:: before the name of the function) you also need to write the declaration of this function in mainwimdow.h. So you need to modify two files (.h and .cpp). 

Now we fill the table with numbers.
Modify code in mainwindow.cpp for "void MainWindow::on_pushButton_clicked()"
When the button is clicked the table should get filled with the multiplication results: (row_index+1) x (column_index + 1).
This is done by the following code: 

```sh
void MainWindow::setItem(int row, int column)
{
    QTableWidgetItem *newItem = new QTableWidgetItem( QObject::tr("%1").arg((row+1)*(column+1)) );
    ui->tableWidget->setItem(row, column, newItem);
}
```

```sh
void MainWindow::on_pushButton_clicked()
{

    for(int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        {
            setItem(i, j);
        }
    }
}
```

The function on_pushButton_clicked() calls the function setItem(int row, int column) which fills the table. Please kindly remember to add declaration of the function setItem(int row, int column) in mainwindow.h.  

### Layout 

The followig code is the constructor of MainWindow class. We add a grid layout to the central widget. We add tableWidget, groupBox and pushButton to the layout. A grid layout is similar to a table. We specify the number of row and colums for each widget.

```sh
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *gridlayout = new QGridLayout(ui->centralwidget);
    gridlayout->addWidget(ui->tableWidget, 0, 0);
    gridlayout->addWidget(ui->groupBox, 0, 1);
    gridlayout->addWidget(ui->pushButton, 1, 0, 1, 2);
}
```
You can notice that widget pushButton has 4 numbers instead of just 2. This is because we want this widget to take 2 cells of the grid layout. 

Try to comment out those lines and run the code. Now stretch the form. Without the layout the widgets will not change their side. 
See no_layout.jpeg. 

![no_layout](https://github.com/marymex/QT_layouts_buttons_tableWidget/blob/master/no_layout.jpeg)

