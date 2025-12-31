#include "creatorbase.h"

CreatorBase::CreatorBase(QObject *parent)
    : QObject{parent}
{}

void CreatorBase::createQmlObject(const QUrl &qmlFileUrl, QQuickItem* visualParent)
{

    if (m_engine==nullptr || visualParent==nullptr) {
        qWarning() << "No se encontro un Qml Engine o Parent o alguna webada mas";
        return;
    }

    QQmlComponent component(m_engine, qmlFileUrl);
    if (component.isError()) {
        qWarning() << "Error loading QML:" << component.errors();
        return;
    }

    BaseTemplate* obj = qobject_cast<BaseTemplate*>(component.create());
    obj->setIde(idCounter++);
    obj->setParent(this->parent());
    //parent visual
    if (visualParent) {
        obj->setParentItem(visualParent);
    }

    QSharedPointer<BaseTemplate> qmlObject(obj,[](BaseTemplate* obj) {
        if (obj) {
            qDebug() << "Deleting entity with ID:" << obj->ide();
            obj->disconnect();
            obj->setParentItem(nullptr);
            obj->setParent(nullptr);
            obj->deleteLater();

        }
    });
    //logica de guardado
    if(m_templateList.isEmpty())m_templateList.append(qmlObject);
    else {
       m_libraryList.append(qmlObject);
    }

}

void CreatorBase::borrarItem(const int id)
{
    for (int i = 0; i < m_libraryList.size(); ++i) {
        if (m_libraryList[i] && m_libraryList[i].data()->ide() == id) {
            m_libraryList.removeAt(i);
            break;
        }
    }
}

void CreatorBase::cantidadItemRestantes()
{
    if (!m_libraryList.empty()) {
        //items restantes
        qDebug()<<"items en la lista: "<<m_libraryList.size();
        for (int i = 0; i < m_libraryList.size(); ++i) {
            qDebug()<<m_libraryList[i];
        }
    }

}
