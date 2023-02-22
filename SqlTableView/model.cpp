#include "model.h"
#include <QDebug>
#include <QSqlRecord>

Model::Model(QObject* parent)
    : QSqlQueryModel(parent)
{

}

// Method for getting data from the model (standard code from documentation example)
// Метод для получения данных из модели (стандартный код из примера в документации)
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
// Метод для получения имен ролей через хешированную таблицу  (стандартный код из примера в документации)
QHash<int, QByteArray> Model::roleNames() const
{
    // It's important that you set this
    // otherwise the display won't work in QML
    // Важно, чтобы вы установили это
    // В противном случае отображение не будет работать в QML
    return { {Qt::DisplayRole, "display"} };
}
