#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H

#include <QAbstractListModel>
#include "employee.h"

class PlanningModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PlanningRoles {
        employeeName
    };

    explicit PlanningModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void addEmployee(const Employee &employee);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Employee> m_employees;
};

#endif // PLANNINGMODEL_H
