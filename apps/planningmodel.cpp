#include "planningmodel.h"

PlanningModel::PlanningModel()
{
    m_employees << Employee("Leona Everett");
    m_employees << Employee("Reuben Hart");
    m_employees << Employee("Kristina Byrd");
    m_employees << Employee("Erica Harmon");
    m_employees << Employee("Martin Randolph");
    m_employees << Employee("Zack John");

    m_firstDate = QDate::currentDate();
    m_interval = month;

}

QString PlanningModel::firstDate() const {
    return m_firstDate.toString("dd/MM/yyyy");
}
void PlanningModel::setFirstDate(QString date, QString format) {
    m_firstDate = QDate::fromString(date, format);
}

/* SIGNAL */
void PlanningModel::updateCalendar() {
    calendarUpdated();
}
/*
QList<Employee> m_employees;
interval m_interval;
QDate m_firstDate;
*/
