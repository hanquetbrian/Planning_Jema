#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H
#include <QObject>
#include <QDate>
#include "employee.h"

class PlanningModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstDate READ firstDate WRITE setFirstDate NOTIFY calendarUpdated)

public:
    enum interval {
        day,
        week,
        month,
        year
    };

    PlanningModel();

    QString firstDate() const;
    void setFirstDate(QString date, QString format = "dd/MM/yyyy");

signals:
    void newEmployee();
    void calendarUpdated();

public slots:
    void updateCalendar();

private:
    QList<Employee> m_employees;
    interval m_interval;
    QDate m_firstDate;

};

#endif // PLANNINGMODEL_H
