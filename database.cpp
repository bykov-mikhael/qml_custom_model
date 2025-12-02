#include "database.hpp"

Database::Database(QObject *parent) : QObject{parent} {

  this->connect();

  for (int var = 0; var < 4; ++var) {
    QVariantList data;
    int random = rand();
    data.append(QDate::currentDate());
    data.append(QTime::currentTime());
    data.append(random);
    data.append("recieved from " + QString::number(random));
    insert(data);
  }
}

Database::~Database() {}

void Database::connect() {
  if (!QFile("../db.sqlite3").exists()) {
    restoreDB();
  } else {
    openDb();
  }
}

bool Database::insert(const QVariantList &data) {
  QSqlQuery query;

  query.prepare(
      "INSERT INTO TBL (TABLE_DATE, TABLE_TIME, TABLE_RANDOM, TABLE_MESSAGE) "
      "VALUES (:Date, :Time, :Random, :Message)");
  query.bindValue(":Date", data[0].toDate());
  query.bindValue(":Time", data[1].toTime());
  query.bindValue(":Random", data[2].toInt());
  query.bindValue(":Message", data[3].toString());

  if (!query.exec()) {
    qDebug() << "error insert";
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool Database::openDb() {
  _db = QSqlDatabase::addDatabase("QSQLITE");
  _db.setHostName("localhost");
  _db.setDatabaseName("../db.sqlite3");

  if (_db.open()) {
    return true;
  } else {
    return false;
  }
}

bool Database::restoreDB() {
  if (openDb()) {
    if (!createTable()) {
      return false;
    } else {
      return true;
    }
  } else {
    qDebug() << "restore db error";
    return false;
  }
}

void Database::closeDB() { _db.close(); }

bool Database::createTable() {
  QSqlQuery query;
  if (!query.exec("CREATE TABLE IF NOT EXISTS TBL (TABLE_ID INTEGER PRIMARY "
                  "KEY AUTOINCREMENT, "
                  "TABLE_DATE DATE NOT NULL, "
                  "TABLE_TIME TIME NOT NULL, "
                  "TABLE_RANDOM INTEGER NOT NULL, "
                  "TABLE_MESSAGE VARCHAR(255) NOT NULL)")) {
    qDebug() << "db error create";
    qDebug() << query.lastError();
    return false;
  } else {
    return true;
  }
  return false;
}
