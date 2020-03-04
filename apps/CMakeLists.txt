set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 LinguistTools REQUIRED)

set(TS_FILES ../translate/planning_software_fr_FR.ts)
set(SOURCES main.cpp planningmodel.cpp qml.qrc)
set(HEADERS include/planningmodel.h)


add_executable(app
        ${SOURCES}
        ${HEADERS}
        ${TS_FILES}
)

target_compile_definitions(app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

# Qt Library
target_link_libraries(app
  PRIVATE Qt5::Core Qt5::Quick Qt5::QuickControls2)

target_include_directories(app PRIVATE resource/)
target_include_directories(app PRIVATE include/)

# Planning lib
target_link_libraries(app PRIVATE planning_lib)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
