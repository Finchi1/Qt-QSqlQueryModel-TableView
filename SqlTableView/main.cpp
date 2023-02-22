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
    // »нициализируем базу данных
    DataBase db;

    // We declare and initialize the data representation model
    // ќбъ€вл€ем и инициализируем модель представлени€ данных
    Model* model = new Model();

    /* Since We have inherited from QSqlQueryModel, then
    * to fetch data, we need to execute a SQL query,
    * in which we will select all the required fields from the table we need
    * */
    /* ѕоскольку ћы отнаследовались от QSqlQueryModel, то
     * дл€ выборки данных нам необходимо выполнить SQL-запрос,
     * в котором мы выберем все необходимы пол€ из нужной нам таблицы
     * */

    model->setQuery("SELECT " + TABLE_DATE + ", " + TABLE_TIME + ", " + TABLE_MESSAGE + ", " + TABLE_RANDOM + " FROM " + TABLE);

    /* And this is already familiar from the lessons on signals and slots in QML
    * We place the resulting model in the QML context so that it is possible
    * refer to the model named "myModel"
    * */
    /* ј это уже знакомо из уроков по сигналам и слотам в QML
     * ѕомещаем полученную модель в контекст QML, чтобы была возможность
     * обращатьс€ к модели по имени "myModel"
     * */

    engine.rootContext()->setContextProperty("myModel", model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
