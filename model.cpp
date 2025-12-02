#include "model.hpp"

Model::Model(QObject *parent) { ; }

QVariant Model::data(const QModelIndex &index, int role) const {
  int columnId = role - Qt::UserRole - 1;
  QModelIndex modelIndex = this->index(index.row(), columnId);
  return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> Model::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[DateRole] = "date";
  roles[TimeRole] = "time";
  roles[RandomRole] = "random";
  roles[MessageRole] = "message";
  return roles;
}
