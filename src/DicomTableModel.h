#ifndef DICOM_TABLE_MODEL_H
#define DICOM_TABLE_MODEL_H

#include <QAbstractTableModel>

class DicomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DicomTableModel(QObject *parent = nullptr);
    Q_INVOKABLE void reloadTable();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    void loadFromSql();
    QList<QList<QString>> table;
};

#endif
