
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "calendarmodel.h"
#include "planningmodel.h"

#include "../include/version_config.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<CalendarModel>("CalendarModel", 1, 0, "CalendarModel");
    qmlRegisterType<PlanningModel>("PlanningModel", 1, 0, "PlanningModel");

    engine.load(QUrl(QStringLiteral("qrc:/resource/main.qml")));

    QObject *mainWindows = engine.rootObjects().first();

    mainWindows->setProperty("project_ver", PROJECT_VERSION);

    return app.exec();
}
