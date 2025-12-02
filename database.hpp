#pragma once

#include <QDate>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Database : public QObject {
  Q_OBJECT

public:
  explicit Database(QObject *parent = nullptr);
  ~Database();

  void connect();
  bool insert(const QVariantList &data);

private:
  QSqlDatabase _db;

  bool openDb();
  bool restoreDB();
  void closeDB();
  bool createTable();
};
