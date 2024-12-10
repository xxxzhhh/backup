#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    bool openDatabase();
    bool authenticateUser(const QString &username, const QString &password, QString &errorMessage);//登录并返回错误信息
    bool registerUser(const QString &username, const QString &password, QString &errorMessage);  // 注册并返回错误信息
    bool isUsernameExist(const QString &username);  // 检查用户名是否已存在
    bool isPasswordStrong(const QString &password);  // 检查密码强度
    ~DatabaseManager();

private:
    DatabaseManager();
    QSqlDatabase db;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
};

#endif // DATABASEMANAGER_H
