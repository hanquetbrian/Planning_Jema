#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QDate>
#include "employee.h"

class CalendarModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PlanningRoles {
        employeeName,
        firstDate,
        nbDayToSee
    };

    explicit CalendarModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void addEmployee(const Employee &employee);
    void setEmployees(const QList<Employee>& employee);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Employee> m_employees;
};

#endif // CALENDARMODEL_H
