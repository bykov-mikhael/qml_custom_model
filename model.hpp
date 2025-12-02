#pragma once

#include <QObject>
#include <QSqlQueryModel>

class Model : public QSqlQueryModel {
  Q_OBJECT
public:
  enum Roles { DateRole = Qt::UserRole + 1, TimeRole, RandomRole, MessageRole };
  explicit Model(QObject *parent = 0);

  QVariant data(const QModelIndex &index, int role) const;

protected:
  QHash<int, QByteArray> roleNames() const;
};
