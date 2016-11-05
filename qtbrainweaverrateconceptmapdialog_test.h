#ifndef QTBRAINWEAVERRATECONCEPTMAPDIALOG_TEST_H
#define QTBRAINWEAVERRATECONCEPTMAPDIALOG_TEST_H

#include <QtTest/QtTest>

namespace ribi {
namespace braw {

class qtbrainweaverrateconceptmapdialog_test : public QObject
{
    Q_OBJECT //!OCLINT

private slots:
  void file_must_match_getfile();
  void save();
  void widget_must_be_initialized();
};

} //~namespace braw
} //~namespace ribi

#endif // QTBRAINWEAVERRATECONCEPTMAPDIALOG_TEST_H
