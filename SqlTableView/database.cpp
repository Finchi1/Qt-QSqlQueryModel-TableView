#include "database.h"
#include <QString>
#include <random>
#include <QDate>

DataBase::DataBase(QObject* parent)
    : QObject{ parent }
{
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(DATABASE_NAME);
    if (!mDb.open())
    {
        qDebug() << "DataBase::DataBase - Error while open database example.db";
        return;
    }
    QSqlQuery query;
    QString queryString = QString
    {
            R"(CREATE TABLE IF NOT EXISTS %1 (
        %2 INTEGER,
        %3 INTEGER,
        %4 VARCHAR(80),
        %5 INTEGER);)"
    }.arg(TABLE, TABLE_DATE, TABLE_TIME, TABLE_MESSAGE, TABLE_RANDOM);
    if (!query.exec(queryString))
        qDebug() << "DataBase::DataBase - Can't create table, wrong query";
    for (int i = 0; i < 4; i++)
    {
        QVariantList data;
        int dt = QDateTime::currentDateTime().toMSecsSinceEpoch();
        int t = QTime::currentTime().msecsSinceStartOfDay();
        int random = std::mt19937(std::random_device{}())() % 1000;
        data.append(dt - t);                                          // date
        data.append(t);                                             // time
        data.append("Get message from " + QString::number(random)); // message
        data.append(random);                                        // random
        if (!insertIntoTable(TABLE, data))
            qDebug() << "DataBase::DataBase - Error while insert data";
    }
}

DataBase::~DataBase()
{
    if (mDb.isOpen())
        mDb.close();
}

bool DataBase::insertIntoTable(const QString tableName, const QVariantList& data)
{
    QString queryString = QString
    {
            R"(INSERT INTO %1 (%2, %3, %4, %5)
           VALUES (%6, %7, '%8', %9); )"
    }.arg(tableName, TABLE_DATE, TABLE_TIME, TABLE_MESSAGE, TABLE_RANDOM).arg(data.at(0).toInt()).arg(data.at(1).toInt()).arg(data.at(2).toString()).arg(data.at(3).toInt());
    QSqlQuery query;
    query.prepare(queryString);
    if (!query.exec())
    {
        qDebug() << "<DataBase::insertIntoTable - Error while insert data" << query.lastError();
        return false;
    }
    else
        return true;
}
