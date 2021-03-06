#include "qtbrainweaverclustertreewidgetitem.h"

#include <stdexcept>
#include <sstream>

QTreeWidgetItem * ribi::braw::QtClusterTreeWidgetItem::clone() const
{
  QtClusterTreeWidgetItem * const item {
    new QtClusterTreeWidgetItem(
      m_competency,
      m_is_complex,
      m_rating_complexity,
      m_rating_concreteness,
      m_rating_specifity
    )
  };
  item->setText(0, this->text(0));
  return item;
}

ribi::braw::QtClusterTreeWidgetItem::QtClusterTreeWidgetItem(
  const ribi::cmap::Competency competency,
  const bool is_complex,
  const int rating_complexity,
  const int rating_concreteness,
  const int rating_specifity)
  : QTreeWidgetItem(0),
    m_competency(competency),
    m_is_complex(is_complex),
    m_rating_complexity(rating_complexity),
    m_rating_concreteness(rating_concreteness),
    m_rating_specifity(rating_specifity)
{
  if (m_rating_complexity < -1 || m_rating_complexity > 2)
  {
    std::stringstream msg;
    msg << __func__ << ": "
      << "rating_complexity must be [-1,2], "
      << "supplied value: " << m_rating_complexity
    ;
    throw std::invalid_argument(msg.str());
  }
  if (m_rating_concreteness < -1 || m_rating_concreteness > 2)
  {
    std::stringstream msg;
    msg << __func__ << ": "
      << "rating_concreteness must be [-1,2], "
      << "supplied value: " << m_rating_concreteness
    ;
    throw std::invalid_argument(msg.str());
  }
  if (m_rating_specifity < -1 || m_rating_specifity > 2)
  {
    std::stringstream msg;
    msg << __func__ << ": "
      << "m_rating_specifity must be [-1,2], "
      << "supplied value: " << m_rating_specifity
    ;
    throw std::invalid_argument(msg.str());
  }
}

bool ribi::braw::operator==(
  const QtClusterTreeWidgetItem& lhs,
  const QtClusterTreeWidgetItem& rhs
) noexcept
{
  return lhs.m_competency == rhs.m_competency
    && lhs.m_is_complex == rhs.m_is_complex
    && lhs.m_rating_complexity == rhs.m_rating_complexity
    && lhs.m_rating_concreteness == rhs.m_rating_concreteness
    && lhs.m_rating_specifity == rhs.m_rating_specifity
  ;

}
