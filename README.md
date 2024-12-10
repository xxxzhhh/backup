构建数据库用到的命令（我新建了一个数据库）

create database backup;

use backup;

create table users(
     id int primary key auto_increment,
     username varchar(20) unique,
     password char(30)
) ;

直接进行git clone就行
