#include "qtbrainweaver_test.h"

#include "qtbrainweaverclusterdialog.h"
#include "qtbrainweaverclusterdialogcloser.h"
#include "qtbrainweaverconceptmapdialog.h"
#include "qtbrainweaverconceptmapdialogcloser.h"
#include "brainweaverfilefactory.h"
#include "qtbrainweaverstudentmenudialog.h"
#include "qtbrainweaverstudentstartdialog.h"
#include "qtbrainweaverstudentstartdialogcloser.h"
#include "ui_qtbrainweaverstudentmenudialog.h"

void ribi::braw::QtTest::ModifiedFileAfterEditConceptMapOk() const noexcept
{
  const File file_before = FileFactory().GetUnrated();
  QtClusterDialog d(file_before);
  assert(file_before == d.ToFile());

  d.show();

  QtConceptMapDialogCloser c;
  QSKIP("TODO: Does not work on Travis", "WIP");
  QTimer::singleShot(200, &c, SLOT(Modify()));
  QTimer::singleShot(400, &c, SLOT(PressOk()));
  d.on_button_next_clicked();

  assert("Closed the ConceptMapDialog (would freeze otherwise)");

  const File file_after = d.ToFile();
  QVERIFY(file_before != file_after);
}

void ribi::braw::QtTest::SameFileAfterEditConceptMapCancelled() const noexcept
{
  const File file_before = FileFactory().GetUnrated();
  QtClusterDialog d(file_before);
  assert(file_before == d.ToFile());

  d.show();

  QtConceptMapDialogCloser c;
  QTimer::singleShot(200, &c, SLOT(Modify()));
  QTimer::singleShot(400, &c, SLOT(PressCancel()));
  d.on_button_next_clicked();

  assert("Closed the ConceptMapDialog (would freeze otherwise)");

  const File file_after = d.ToFile();
  QVERIFY(file_before == file_after);
}

void ribi::braw::QtTest::AcceptedClusterDialogChangesAreStored() const noexcept
{
  // Create a file for a student, using Developer
  const File f = FileFactory().GetFocalQuestionOnly();

  // Load the empty file, fill in name, cluster, save
  QtStudentMenuDialog menu(f);
  menu.SetName("John Doe");

  QtStudentStartDialogCloser start_closer;
  QtClusterDialogCloser cluster_closer;

  // Navigate backwards to menu using OK
  QTimer::singleShot(100, &start_closer, SLOT(PressStartAssociate()));
  QTimer::singleShot(200, &cluster_closer, SLOT(Modify()));
  QTimer::singleShot(300, &cluster_closer, SLOT(PressOk())); //Saves and closes
  QTimer::singleShot(400, &start_closer, SLOT(Close()));

  QVERIFY(f != menu.GetFile());
}

void ribi::braw::QtTest::AcceptedConceptMapChangesAreStored() const noexcept
{
  // Create a file for a student, using Developer
  const File f = FileFactory().GetFocalQuestionOnly();

  // Load the empty file, fill in name, cluster, save
  QtStudentMenuDialog menu(f);
  menu.SetName("John Doe");

  QtStudentStartDialogCloser start_closer;
  QtConceptMapDialogCloser concept_map_dialog_closer;

  // Navigate backwards to menu using OK
  QTimer::singleShot(100, &start_closer, SLOT(PressStartConceptMap()));
  QTimer::singleShot(200, &concept_map_dialog_closer, SLOT(Modify()));
  QTimer::singleShot(300, &concept_map_dialog_closer, SLOT(PressOk())); //Saves and closes
  QTimer::singleShot(400, &start_closer, SLOT(Close()));

  QVERIFY(f != menu.GetFile());
}
