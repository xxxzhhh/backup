#ifndef REGISTER1_H
#define REGISTER1_H

#include <QDialog>
#include "databasemanager.h"
#include <QMessageBox>

namespace Ui {
class register1;
}

class register1 : public QDialog
{
    Q_OBJECT

public:
    explicit register1(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~register1();

private slots:
    void on_register_btn_clicked();

    void on_backup_btn_clicked();

private:
    Ui::register1 *ui;
    DatabaseManager *dbManager;
};

#endif // REGISTER1_H
