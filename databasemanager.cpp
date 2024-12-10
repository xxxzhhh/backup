#include "databasemanager.h"
#include <QDebug>
#include <QRegularExpression>
#include <QSqlQuery>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::openDatabase()
{
    db.setHostName("localhost");
    db.setDatabaseName("backup");
    db.setUserName("root");
    db.setPassword("QJJ123456");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::isUsernameExist(const QString &username)
{
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;  // 如果用户名已经存在，返回 true
    }
    return false;
}

bool DatabaseManager::isPasswordStrong(const QString &password)
{
    // 密码强度检查规则：至少8个字符，包含大写字母，小写字母和数字
    QRegularExpression passwordRegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    return passwordRegExp.match(password).hasMatch();  // 使用 QRegularExpression 进行匹配
}

bool DatabaseManager::authenticateUser(const QString &username, const QString &password, QString &errorMessage)
{
    QSqlQuery query(db);
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec()) {
        if (query.next()) {
            QString dbPassword = query.value(0).toString();
            if (dbPassword == password) {
                return true;  // 登录成功
            } else {
                errorMessage = "Incorrect password!";
                return false;  // 密码错误
            }
        } else {
            errorMessage = "Username not found!";
            return false;  // 用户名不存在
        }
    } else {
        errorMessage = "Database query failed!";
        return false;  // 查询失败
    }
}

bool DatabaseManager::registerUser(const QString &username, const QString &password, QString &errorMessage)
{
    // 检查用户名是否已存在
    if (isUsernameExist(username)) {
        errorMessage = "Username already exists!";
        return false;
    }

    // 检查密码是否符合强度要求
    if (!isPasswordStrong(password)) {
        errorMessage = "Password is too weak! It should contain at least 8 characters, including uppercase letters, lowercase letters, and digits.";
        return false;
    }

    // 如果用户名不存在且密码强度符合要求，则执行注册
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        return true;
    } else {
        errorMessage = "Registration failed: " + query.lastError().text();
        return false;
    }
}
