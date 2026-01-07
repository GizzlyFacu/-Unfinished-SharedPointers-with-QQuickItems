#include "templatecontainer.h"

TemplateContainer::TemplateContainer() {}

QQmlListProperty<BaseTemplate> TemplateContainer::templatesViews()
{
    return QQmlListProperty<BaseTemplate>(this, &m_templates);
}

void TemplateContainer::addItem(BaseTemplate* item)
{
    if (!item || m_templates.contains(item))
        return;

    item->setParentItem(this);   // parent visual
    m_templates.append(item);

    // Layout simple vertical
    item->setY((m_templates.size() - 1) * item->height());
    this->setHeight(m_templates.size()*item->height());
    qDebug()<<"TemplateContainer::addItem tamanio del container: "<<this->height();

    qDebug()<<"TemplateContainer::addItem cantidad de templates: "<<m_templates.size();
    emit templateViewsChanged();
}

void TemplateContainer::removeItem(const int id)
{
    for (int i = 0; i < m_templates.size(); ++i) {
        if (m_templates[i] && m_templates[i]->ide() == id) {
            m_templates.removeAt(i);
            break;
        }
    }
    emit templateViewsChanged();
}
