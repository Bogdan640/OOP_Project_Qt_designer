#include "TableModel.h"
using namespace std;

TableModel::TableModel(Shopping_basket& sb, QObject *parent) : shopping_basket{ sb },
                                                                      QAbstractTableModel{ parent }{}

int TableModel::rowCount(const QModelIndex & parent) const
{
    return this->shopping_basket.getCoats().size();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
    return 5;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    vector<Coat> Coats = this->shopping_basket.getCoats();
    Coat Coat = Coats[row];
    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(Coat.get_size());
            case 1:
                return QString::fromStdString(Coat.get_colour());
            case 2:
                return QString::number(Coat.get_price());
            case 3:
                return QString::number(Coat.get_quantity());
            case 4:
                return QString::fromStdString(Coat.get_photo());
            default:
                break;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section)
        {
            case 0:
                return QString("Size");
            case 1:
                return QString("Colour");
            case 2:
                return QString("Price");
            case 3:
                return QString("Quantity");
            case 4:
                return QString("Photo link");
            default:
                return QVariant();
        }
    }
    return QVariant();
}