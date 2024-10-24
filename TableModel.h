#pragma once
#include <qabstractitemmodel.h>
#include "shopping_basket.h"

class TableModel : public QAbstractTableModel
{
private:
    Shopping_basket& shopping_basket;

public:
    TableModel(Shopping_basket& shopping_basket, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

