#pragma once

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QString>

/* Directives for table names, table fields, and database fields */
/* Директивы имен таблицы, полей таблицы и базы данных */
const QString DATABASE_HOSTNAME = "ExampleDataBase";
const QString DATABASE_NAME = "example.db";

const QString TABLE = "TableExample";
const QString TABLE_DATE = "date";
const QString TABLE_TIME = "time";
const QString TABLE_MESSAGE = "message";
const QString TABLE_RANDOM = "random";

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject* parent = nullptr);
    virtual ~DataBase();

    bool insertIntoTable(const QString tableName, const QVariantList& data);

private:
    QSqlDatabase mDb;
};

