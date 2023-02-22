#include "model.h"
#include <QDebug>
#include <QSqlRecord>

Model::Model(QObject* parent)
    : QSqlQueryModel(parent)
{

}

// Method for getting data from the model (standard code from documentation example)
// ����� ��� ��������� ������ �� ������ (����������� ��� �� ������� � ������������)
QVariant Model::data(const QModelIndex& index, int role) const
{
    QVariant value;

    if (role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

// Method for getting role names via hashed table (standard code from documentation example)
// ����� ��� ��������� ���� ����� ����� ������������ �������  (����������� ��� �� ������� � ������������)
QHash<int, QByteArray> Model::roleNames() const
{
    // It's important that you set this
    // otherwise the display won't work in QML
    // �����, ����� �� ���������� ���
    // � ��������� ������ ����������� �� ����� �������� � QML
    return { {Qt::DisplayRole, "display"} };
}
