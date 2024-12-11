#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("backup pack");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_backup_btn_clicked()
{
    QMessageBox::information(this, "backup", "Please backup now");
}


void MainWindow::on_restore_btn_clicked()
{
    QMessageBox::information(this, "restore", "Please restore now");
}

