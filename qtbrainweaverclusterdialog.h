#ifndef QTBRAINWEAVERCLUSTERDIALOG_H
#define QTBRAINWEAVERCLUSTERDIALOG_H

#include <QDialog>
#include "brainweaverfile.h"
#include "qtbrainweaverfwd.h"

namespace Ui { class QtClusterDialog; }

namespace ribi {
namespace braw {

class QtClusterDialogCloser;
class QtClusterDialogTest;

///The Dialog in which the user clusters concepts and examples
///If the file supplied has no cluster, this dialog creates a cluster
///because the widget needs something to work on
class QtClusterDialog final : public QDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtClusterDialog(const File& file, QWidget* parent = nullptr);
  QtClusterDialog(const QtClusterDialog&) = delete;
  QtClusterDialog& operator=(const QtClusterDialog&) = delete;
  ~QtClusterDialog() noexcept;

  const Ui::QtClusterDialog * GetUi() const noexcept { return ui; }
        Ui::QtClusterDialog * GetUi()       noexcept { return ui; }

  ///Obtain the widget
  QtClusterWidget * GetWidget();
  const QtClusterWidget * GetWidget() const;

  ///Does the dialog want to go back to the student menu?
  bool GoBackToMenu() const { return m_back_to_menu; }

  ///Has the user closed the dialog by clicking OK?
  bool HasClickedOk() const noexcept { return m_ok_clicked; }

  //Save to disk
  void Save(const QString& filename);

  ///Create a new file from the dialog
  File ToFile() const;

protected:
  ///Respond to the following keys:
  ///F2: edit current item
  ///Delete: remove current item
  void keyPressEvent(QKeyEvent *);

public slots:

  void on_button_add_clicked();
  void on_button_next_clicked();

  void on_button_save_clicked();

private slots:
  void on_button_cancel_clicked();

  void on_button_ok_clicked();

private:
  Ui::QtClusterDialog *ui;

  ///Does the dialog want to go back to the student menu?
  bool m_back_to_menu;

  ///The initial file
  File m_file;

  ///Has the user clicked OK?
  bool m_ok_clicked{false};

  ///The cluster widget
  QtClusterWidget * const m_widget;


  //Start saving procedure, with request of filename
  void Save();

  friend class QtClusterDialogCloser;
  friend class QtClusterDialogTest;
};

///Add a Cluster to the file if it is not yet present,
///Create a QtClusterWidget from the file its cluster
QtClusterWidget * BuildWidget(File file);

} //~namespace braw
} //~namespace ribi

#endif // QTBRAINWEAVERCLUSTERDIALOG_H
