#include "planningmodel.h"

PlanningModel::PlanningModel(QObject *parent)
    : QAbstractListModel(parent) {
    m_employees << Employee("Leona Everett");
    m_employees << Employee("Reuben Hart");
    m_employees << Employee("Kristina Byrd");
    m_employees << Employee("Erica Harmon");
    m_employees << Employee("Martin Randolph");
    m_employees << Employee("Zack John");

}

int PlanningModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_employees.count();
}

void PlanningModel::addEmployee(const Employee &employee) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_employees << employee;
    endInsertRows();
}

QVariant PlanningModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Employee &employee = m_employees[index.row()];
    if (role == employeeName) {
        return QString::fromStdString(employee.getName());
    }
    return QVariant();
}

QHash<int, QByteArray> PlanningModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[employeeName] = "employeeName";
    return roles;
}
