#include "DicomTableModel.h"
#include "DatabaseConnection.h"

DicomTableModel::DicomTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    DatabaseConnection db("app_database");
    table = db.executeQuery("select * from patients INNER JOIN exams ON exams.patientsId = patients.id");
}

int DicomTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return table.size();
}

int DicomTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
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
