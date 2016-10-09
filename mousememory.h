#ifndef MOUSEMEMORY_H
#define MOUSEMEMORY_H

#include <QObject>
#include <QDebug>
#include <QPoint>

class MouseMemory : public QObject
{
    Q_OBJECT
public:
    explicit MouseMemory(QObject *parent = 0);

    // Q_INVOKABLE - это макрос, который говорит, что функция test должна вызываться из QML
    Q_INVOKABLE void test();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void save();
    Q_INVOKABLE void add(double x, double y);
    Q_INVOKABLE void add(QPointF point);

signals:

public slots:
};

#endif // MOUSEMEMORY_H
