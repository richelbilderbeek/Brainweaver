//---------------------------------------------------------------------------
/*
Brainweaver, tool to create and assess concept maps
Copyright (C) 2012-2016 The Brainweaver Team

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ProjectBrainweaver.htm
//---------------------------------------------------------------------------
#ifndef QTBRAINWEAVERMENUDIALOG_H
#define QTBRAINWEAVERMENUDIALOG_H

#include "qtbrainweaverdialog.h"
#include "brainweaverfile.h"
#include "brainweaverfwd.h"

namespace Ui { class QtMenuDialog; }

namespace ribi {

namespace braw {

class QtMenuDialog : public QtDialog
{
  Q_OBJECT
    
  public:
  explicit QtMenuDialog(QWidget* parent = 0);
  QtMenuDialog(const QtMenuDialog&) = delete;
  QtMenuDialog& operator=(const QtMenuDialog&) = delete;
  ~QtMenuDialog() noexcept;

  const Ui::QtMenuDialog * GetUi() const noexcept { return ui; }
        Ui::QtMenuDialog * GetUi()       noexcept { return ui; }

public slots:
  void on_button_about_clicked() noexcept;
  void on_button_assessor_clicked() noexcept;
  void on_button_modify_stylesheet_clicked() noexcept;
  void on_button_overview_clicked() noexcept;
  void on_button_print_concept_map_clicked() noexcept;
  void on_button_print_rating_clicked() noexcept;
  void on_button_rate_concept_auto_clicked() noexcept;
  void on_button_rate_concept_clicked() noexcept;
  void on_button_rate_concept_map_clicked() noexcept;
  void on_button_rate_examples_clicked() noexcept;
  void on_button_rating_clicked() noexcept;
  void on_button_student_clicked() noexcept;
  void on_button_test_conceptmap_clicked();
  void on_button_test_cluster_clicked() noexcept;

private slots:
  void keyPressEvent(QKeyEvent* e) noexcept;

  void on_button_empty_qtconceptmap_clicked();

private:
  Ui::QtMenuDialog *ui;

  friend class qtbrainweavermenudialog_test;
};

} //~namespace braw
} //~namespace ribi

#endif // QTBRAINWEAVERMENUDIALOG_H
