#DEFINES += BRAINWEAVER_MOVE_ITEMS_ON_COLLISION

# Most specific first
include(BrainweaverConsole.pri)
include(BrainweaverConsoleTest.pri)

include(../RibiLibraries/BoostAll.pri)


include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

#Specific, console
include(../RibiClasses/CppContainer/CppContainer.pri)
include(../RibiClasses/CppCounter/CppCounter.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppGeometry/CppGeometry.pri)
include(../RibiClasses/CppGrabber/CppGrabber.pri)
include(../RibiClasses/CppPlane/CppPlane.pri)
include(../RibiClasses/CppQtImage/CppQtImage.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)
include(../RibiClasses/CppRibiSystem/CppRibiSystem.pri)
include(../RibiClasses/CppRibiTime/CppRibiTime.pri)
include(../RibiClasses/CppStopwatch/CppStopwatch.pri)
include(../RibiClasses/CppXml/CppXml.pri)

#Specific
include(../ConceptMap/ConceptMap.pri)
include(../BoostGraphTutorial/BoostGraphTutorial/boost_graph_tutorial.pri)

SOURCES += main_test.cpp

# Boost.Test
LIBS += -lboost_unit_test_framework

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# Debug and release settings
CONFIG += debug_and_release
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg
}

CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}

# C++14
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# High warning level, warnings are errors
# -Weffc++ #Qt goes bad with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
QMAKE_CXXFLAGS += -Werror

# Qt
QT += core gui printsupport

