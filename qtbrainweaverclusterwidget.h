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
#ifndef QTBRAINWEAVERCLUSTERWIDGET_H
#define QTBRAINWEAVERCLUSTERWIDGET_H


#include <QTreeWidget>
#include "conceptmapcompetency.h"
#include "brainweavercluster.h"
#include "brainweaverfwd.h"

namespace ribi {
namespace braw {

struct QtClusterTreeWidgetItem;

class QtClusterWidget : public QTreeWidget
{
  Q_OBJECT //!OCLINT

public:
  explicit QtClusterWidget(
    const Cluster& cluster,
    QWidget* parent = 0
  );

  void addTopLevelItem(QTreeWidgetItem *item);

  ///Add a top-level item
  void Add(const std::string& text);

  ///Get the cluster (after reading from the dialog)
  Cluster GetCluster() const noexcept;

protected:
  void dropEvent(QDropEvent *event);

  void keyPressEvent(QKeyEvent *event);

private slots:
  void RemoveEmptyItem(QTreeWidgetItem*,int);

private:
  ///The cluster
  ///Mutable because WriteToCluster updates it when GetCluster is called
  mutable Cluster m_cluster;

  ///Build the widget from the cluster
  void BuildCluster();

  ///Find out the depth of an item
  int GetDepth(const QTreeWidgetItem * const item) const;

  ///Write the widget its data to the cluster
  void WriteToCluster() const noexcept;

  void SetCorrectFlags() noexcept;

  void keyPressEventRight(QKeyEvent *event);
};

} //~namespace braw
} //~namespace ribi

#endif // QTBRAINWEAVERCLUSTERWIDGET_H
