#ifndef TEMPLATECONTAINER_H
#define TEMPLATECONTAINER_H

#include <QQuickItem>
#include <QQmlListProperty>
#include "basetemplate.h"

class TemplateContainer : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QQmlListProperty<BaseTemplate> templatesViews READ templatesViews NOTIFY templateViewsChanged FINAL)
public:
    TemplateContainer();
    QQmlListProperty<BaseTemplate> templatesViews();
    void addItem(BaseTemplate* item);
    void removeItem(const int id);
signals:
    void templateViewsChanged();

private:
    QQmlListProperty<BaseTemplate> m_templatesViews;
    QList<BaseTemplate*> m_templates;
};

#endif // TEMPLATECONTAINER_H
