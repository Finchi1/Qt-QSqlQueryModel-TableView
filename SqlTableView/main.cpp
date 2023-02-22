#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "database.h"
#include "model.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Initialize the database
    // �������������� ���� ������
    DataBase db;

    // We declare and initialize the data representation model
    // ��������� � �������������� ������ ������������� ������
    Model* model = new Model();

    /* Since We have inherited from QSqlQueryModel, then
    * to fetch data, we need to execute a SQL query,
    * in which we will select all the required fields from the table we need
    * */
    /* ��������� �� ��������������� �� QSqlQueryModel, ��
     * ��� ������� ������ ��� ���������� ��������� SQL-������,
     * � ������� �� ������� ��� ���������� ���� �� ������ ��� �������
     * */

    model->setQuery("SELECT " + TABLE_DATE + ", " + TABLE_TIME + ", " + TABLE_MESSAGE + ", " + TABLE_RANDOM + " FROM " + TABLE);

    /* And this is already familiar from the lessons on signals and slots in QML
    * We place the resulting model in the QML context so that it is possible
    * refer to the model named "myModel"
    * */
    /* � ��� ��� ������� �� ������ �� �������� � ������ � QML
     * �������� ���������� ������ � �������� QML, ����� ���� �����������
     * ���������� � ������ �� ����� "myModel"
     * */

    engine.rootContext()->setContextProperty("myModel", model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
