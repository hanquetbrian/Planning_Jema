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

/**
 * @brief The PlanningModel class
 * The PlanningModel contain all the informations to make a model for the planning application
 */
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

    /**
     * This function return the date in an understandable format for the sqlite database
     * @return return the date in the yyyy-MM-dd format
     */
    QString firstDateISOFormat() const;
    /**
     * this fonction allow to get the date from an other format
     * @brief firstDate
     * @param format is the format of the return date
     * @return return the date in the correct format
     */
    QString firstDate(QString format = "dd/MM/yyyy") const;

    /**
     * Change the date to display in the application
     * @brief setFirstDate
     * @param date is the date we want to display
     * @param format is the format we want the date to be
     */
    void setFirstDate(QString date, QString format = "dd/MM/yyyy");

    int interval() const;
    void setInterval(int interval);

    CalendarModel* calendarModel();
signals:
    void newEmployee();
    void calendarUpdated();

public slots:
    QString getDateFormat(QString format = "dd/MM/yyyy") const;
    /**
     * @brief addEmployee add employee to the database and display the new employee
     * @param name is the name of the employee
     * @param hide is a boolean that will decide if we want the employee to be shown
     * @return true if the command success and false is there was an error
     */
    bool addEmployee(QString name, bool hide);

    /**
     * @brief addTaskSO add a new Task to the database and display it on the planning
     * @param title
     * @param so_id is the so ID of we want to add to the planning
     * @param wo_id is the wo id we want to add to the planning
     * @param date_from is the date we want the task to begin
     * @param date_to is the date we want the task to end
     * @param hour_from is the hour we want the task to begin
     * @param hour_to is the hour we want the task to end
     * @param comment is comment we can add on the task
     * @param state is the state of the task (Finished, InProgress, Waiting)
     * @return return true if the task is sucessfully added and false if there was an error
     */
    bool addTaskSO(QString title, int so_id, int wo_id, QDate date_from, QDate date_to, QTime hour_from, QTime hour_to, QString comment, int state);

    /**
     * @brief addTaskTest add a test to the database
     * @param name is a name we can set for the test task
     * @param wo_id is the id of the wo we want to test
     * @param testDate is the date of the test
     * @param comment is a comment we can add for the test
     * @param state is the state of the task (Finished, InProgress, Waiting
     * @return return true if the test is sucessfully added and false if there was an error
     */
    bool addTaskTest(QString name, int wo_id, QDate testDate, QString comment, int state);

private:
    CalendarModel* m_calendarModel;
    Interval m_interval;
    QDate m_firstDate;

    PlanningAbstractData* m_datadb;
};

#endif // PLANNINGMODEL_H
