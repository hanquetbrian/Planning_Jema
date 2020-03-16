#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H
#include <QObject>
#include <QDate>
#include <QList>
#include <QString>
#include "employee.h"
#include "calendarmodel.h"
#include "planningabstractdata.h"
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

    enum TaskState {
        Finished = 0,
        InProgress,
        Waiting
    };

    PlanningModel(PlanningAbstractData* data = new SqlitePlanning());
    ~PlanningModel();

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
    bool addEmployee(QString name, bool hide);
    bool addTaskSO(QString title, int so_id, int wo_id, QDate date_from, QDate date_to, QTime hour_from, QTime hour_to, QString comment, TaskState state);
    bool addTaskTest(QString name, int wo_id, QDate testDate, QString comment, TaskState state);

private:
    CalendarModel* m_calendarModel;
    Interval m_interval;
    QDate m_firstDate;

    PlanningAbstractData* m_datadb;
};

#endif // PLANNINGMODEL_H
