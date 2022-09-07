#include "DicomTableModel.h"
#include "DatabaseConnection.h"

DicomTableModel::DicomTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    loadFromSql();
}

void DicomTableModel::loadFromSql(const QString &condition)
{
    DatabaseConnection db("app_database");
    QString query = "select patients.patientIdentifier, patients.name, patients.gender, patients.age, exams.modality, exams.filePath, exams.acq_date "
            "from exams INNER JOIN patients ON exams.patientIdentifier = patients.patientIdentifier " + condition;
    qDebug() << query;
    table = db.executeQuery(query);
}

void DicomTableModel::resetTable(const QString &condition)
{
    beginResetModel();
    loadFromSql(condition);
    endResetModel();
}

int DicomTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return table.size();
}

int DicomTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    if (table.size() > 0) {
        return table[0].size();
    } else {
        return 0;
    }
}

QVariant DicomTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
       return table[index.row()][index.column()];

    return QVariant();
}

QVariant DicomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("first");
        case 1:
            return QString("second");
        case 2:
            return QString("third");
        }
    }
    return QVariant();
}
