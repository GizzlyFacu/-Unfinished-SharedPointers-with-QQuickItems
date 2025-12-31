#ifndef CREATORBASE_H
#define CREATORBASE_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QQmlComponent>
#include <QQuickItem>
#include <QSharedPointer>
#include "basetemplate.h"
class CreatorBase : public QObject
{
    Q_OBJECT
public:
    explicit CreatorBase(QObject *parent = nullptr);
    void setQmlEngine(QQmlEngine* engine) {
        m_engine = engine;
    }
public slots:
    void createQmlObject(const QUrl &qmlFileUrl, QQuickItem* visualParent);
    void borrarItem(const int id);
    void cantidadItemRestantes();

private:
    QQmlEngine* m_engine=nullptr;
    QList<BaseTemplate*> ObjectList;
    QList<QSharedPointer<BaseTemplate>> m_libraryList;
    QList<QSharedPointer<BaseTemplate>> m_templateList;
    int idCounter=0;
};

#endif // CREATORBASE_H
