#include "DicomTableModel.h"
#include "DatabaseConnection.h"

DicomTableModel::DicomTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    DatabaseConnection db("app_database");
    table = db.executeQuery("select * from exams INNER JOIN patients ON exams.patientIdentifier = patients.patientIdentifier");
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
