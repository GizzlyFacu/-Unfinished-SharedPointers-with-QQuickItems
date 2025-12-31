#ifndef BASETEMPLATE_H
#define BASETEMPLATE_H

#include <QObject>
#include <QQuickItem>
class BaseTemplate : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int ide READ ide WRITE setIde NOTIFY ideChanged FINAL)
public:
    explicit BaseTemplate(QQuickItem *parent = nullptr);

    int ide() const;
    void setIde(int newId);
signals:
    void ideChanged();
private:
    int m_ide;
};

#endif // BASETEMPLATE_H
