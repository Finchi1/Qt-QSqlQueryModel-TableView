#pragma once

#include <QSqlQueryModel>
#include <QObject>

class Model : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum Roles {
        DateRole = Qt::UserRole + 1, // Date
        TimeRole,                    // Time
        MessageRole,                 // Message
        RandomRole                   // Random
    };

    explicit Model(QObject* parent = nullptr);

    // Override the method that will return data
    // �������������� �����, ������� ����� ���������� ������
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

protected:
    /* hashed table of roles for columns.
    * The method is used in the wilds of the QAbstractItemModel base class,
    * from which the QSqlQueryModel class is inherited
    * */
    /* ������������ ������� ����� ��� �������.
     * ����� ������������ � ������ �������� ������ QAbstractItemModel,
     * �� �������� ���������� ����� QSqlQueryModel
     * */
    QHash<int, QByteArray> roleNames() const override;
    QStringList userRoleNames() const;
};

