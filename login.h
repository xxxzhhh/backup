#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "databasemanager.h"
#include "register1.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_btn_clicked();

    void on_register_btn_clicked();

private:
    Ui::login *ui;
    DatabaseManager *dbManager;
};

#endif // LOGIN_H
