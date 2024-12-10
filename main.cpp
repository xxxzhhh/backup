#include "login.h"
#include "databasemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建 DatabaseManager 实例，打开数据库连接
    DatabaseManager& dbManager = DatabaseManager::instance();
    if (!dbManager.openDatabase()) {
        // 如果数据库连接失败，弹出错误消息并退出程序
        QMessageBox::critical(nullptr, "Database Error", "Failed to connect to the database!");
        return -1;
    }

    // 创建 login 窗口，并将 dbManager 实例传递给 login 窗口
    login w(&dbManager);
    w.show();

    // 进入事件循环
    return a.exec();
}
