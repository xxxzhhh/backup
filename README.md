构建数据库用到的命令（我新建了一个数据库）

create database backup;

use backup;

create table users(
     id int primary key auto_increment,
     username varchar(20) unique,
     password char(30)
) ;

直接进行git clone就行

代码说明：

login:负责登录（页面和逻辑）

register1:负责注册（页面和逻辑）

databasemanager:
1. 负责数据库相关的操作
2. 用户注册和用户登录功能全在这里


