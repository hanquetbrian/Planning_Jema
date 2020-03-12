#include "planningmodel.h"

PlanningModel::PlanningModel(PlanningAbstractData* data)
    :m_datadb(data)
{
    m_calendarModel = new CalendarModel();

    m_datadb->connect();
    auto listEmployee = m_datadb->getListEmployee();

    m_calendarModel->setEmployees(QList<Employee>(listEmployee.begin(), listEmployee.end()));

    m_firstDate = QDate::currentDate();
    m_interval = month;

}

PlanningModel::~PlanningModel() {
    delete m_calendarModel;
    m_calendarModel = NULL;
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

bool PlanningModel::addEmployee(QString name, bool hide) {
    Employee employee(name.toStdString(), hide);
    m_datadb->addEmployee(employee);
    m_calendarModel->addEmployee(employee);

    return true;
}
