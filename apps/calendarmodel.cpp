#include "calendarmodel.h"

CalendarModel::CalendarModel(QObject *parent)
    : QAbstractListModel(parent) {
}

int CalendarModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_employees.count();
}

void CalendarModel::addEmployee(const Employee &employee) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_employees << employee;
    endInsertRows();
}

QVariant CalendarModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Employee &employee = m_employees[index.row()];
    switch (role) {
    case employeeName:
        return QString::fromStdString(employee.getName());
    }
    return QVariant();
}

bool CalendarModel::setData(const QModelIndex &index, const QVariant& /*value*/, int role) {
    if (!index.isValid())
        return false;
    if(role == employeeName) {

    }
    return false;
}

QVariant CalendarModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(section < 0 | orientation != Qt::Horizontal) {
        return QVariant();
    }
    if(role == employeeName) {
        return QString("head");
    }
    return QVariant();
}

Qt::ItemFlags CalendarModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CalendarModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[employeeName] = "employeeName";
    return roles;
}
