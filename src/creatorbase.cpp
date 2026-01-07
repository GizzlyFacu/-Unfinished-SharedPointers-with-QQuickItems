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
    m_libraryList.append(qmlObject);
    //logica de mostrado
    BaseTemplate* item = qmlObject.data();
    m_mostrador->addItem(item);
    emit m_mostrador->templateViewsChanged();



    qDebug()<<"nuevo item aniadido al view\n";
    qDebug()<<"lista de los templates: \n"<< m_templateList.size();
    qDebug()<<"lista de la libreria: \n"<< m_libraryList.size();

}

void CreatorBase::createQmlObjectTemplate(const QUrl &qmlFileUrl, QQuickItem *visualParent)
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
    m_templateList.append(qmlObject);



    qDebug()<<"nuevo item aniadido al view\n";
    qDebug()<<"lista de los templates: \n"<< m_templateList.size();
    qDebug()<<"lista de la libreria: \n"<< m_libraryList.size();
}

void CreatorBase::moveToMostrador(const int index, QQuickItem *templateContainers)
{
    //logica de mostrado

    //mover a libreria
    m_libraryList.append(m_templateList.takeAt(index));
    BaseTemplate* item = m_libraryList.at(m_libraryList.size()-1).data();
    //pasar su puntero a mostrador
    item->setProperty("enabledButt",true);
    m_mostrador->addItem(item);
    emit m_mostrador->templateViewsChanged();
    //crear nuevo
    const QUrl templateBase=QUrl("qrc:/assets/TemplateCreator.qml");
    createQmlObjectTemplate(templateBase,templateContainers);
}

QQuickItem *CreatorBase::getTemplate()
{
    if(m_templateList.isEmpty()){
        qWarning()<<"[Warning] CreatorBase::getTemplate(): m_templateList ta vacio";
        return nullptr;
    }
    QQuickItem* templeit=m_templateList.at(0).data();
    return templeit;
}


void CreatorBase::borrarItem(const int id)
{
    m_mostrador->removeItem(id);
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
