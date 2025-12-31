#include "basetemplate.h"

BaseTemplate::BaseTemplate(QQuickItem *parent)
    : QQuickItem{parent}
{}


int BaseTemplate::ide() const
{
    return m_ide;
}

void BaseTemplate::setIde(int newId)
{
    if (m_ide == newId)
        return;
    m_ide = newId;
    emit ideChanged();
}
