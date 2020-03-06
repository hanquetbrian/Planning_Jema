#include "planningmodel.h"

PlanningModel::PlanningModel()
{
    m_calendarModel = new CalendarModel();
    m_calendarModel->addEmployee(Employee("Leona Everett"));
    m_calendarModel->addEmployee(Employee("Reuben Hart"));
    m_calendarModel->addEmployee(Employee("Kristina Byrd"));
    m_calendarModel->addEmployee(Employee("Erica Harmon"));
    m_calendarModel->addEmployee(Employee("Martin Randolph"));
    m_calendarModel->addEmployee(Employee("Zack John"));

    m_firstDate = QDate::currentDate();
    m_interval = month;

    sqliteEmployee test {"planning.db"};
    test.connect();
    test.close();

}
QString PlanningModel::firstDateISOFormat() const {
    return m_firstDate.toString("yyyy-MM-dd");
}

QString PlanningModel::firstDate(QString format) const {
    return m_firstDate.toString(format);
}
void PlanningModel::setFirstDate(QString date, QString format) {
    m_firstDate = QDate::fromString(date, format);
    calendarUpdated();
}


int PlanningModel::interval() const {
    return m_interval;
}
void PlanningModel::setInterval(int interval) {
    switch (interval) {
    case 0:
        m_interval = PlanningModel::Interval::day;
        break;
    case 1:
        m_interval = PlanningModel::Interval::week;
        break;
    case 2:
        m_interval = PlanningModel::Interval::month;
        break;
    case 3:
        m_interval = PlanningModel::Interval::year;
        break;
    }

    calendarUpdated();
}

CalendarModel* PlanningModel::calendarModel() {
    return m_calendarModel;
}

/* SLOTS */
QString PlanningModel::getDateFormat(QString format) const {
    return firstDate(format);
}
