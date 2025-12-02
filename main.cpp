#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "database.hpp"
#include "model.hpp"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  Database db;

  Model *model = new Model();

  model->setQuery("select * from tbl");

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml_custom_model/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);

  engine.rootContext()->setContextProperty("myModel", model);

  engine.load(url);

  return app.exec();
}
