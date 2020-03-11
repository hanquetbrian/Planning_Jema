#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H
#include <QObject>
#include <QDate>
#include <QList>
#include "employee.h"
#include "calendarmodel.h"
#include "sqliteplanning.h"

class PlanningModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstDate READ firstDate WRITE setFirstDate NOTIFY calendarUpdated)
    Q_PROPERTY(QString firstDateISOFormat READ firstDateISOFormat NOTIFY calendarUpdated)
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY calendarUpdated)
    Q_PROPERTY(CalendarModel* calendarModel READ calendarModel NOTIFY calendarUpdated)

public:
    enum Interval {
        day = 0,
        week,
        month,
        year
    };

    PlanningModel();

    QString firstDateISOFormat() const;
    QString firstDate(QString format = "dd/MM/yyyy") const;
    void setFirstDate(QString date, QString format = "dd/MM/yyyy");

    int interval() const;
    void setInterval(int interval);

    CalendarModel* calendarModel();
signals:
    void newEmployee();
    void calendarUpdated();

public slots:
    QString getDateFormat(QString format = "dd/MM/yyyy") const;


private:
    CalendarModel* m_calendarModel;
    Interval m_interval;
    QDate m_firstDate;
};

#endif // PLANNINGMODEL_H
