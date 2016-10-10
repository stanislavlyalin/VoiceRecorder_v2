#ifndef MOUSEMEMORY_H
#define MOUSEMEMORY_H

#include <QObject>
#include <QDebug>
#include <QAudioRecorder>
#include <QUrl>
#include <QGuiApplication>

class MouseMemory : public QObject
{
    Q_OBJECT

public:
    explicit MouseMemory(QObject *parent = 0);

    // Q_INVOKABLE - это макрос, который говорит, что функция должна вызываться из QML
    Q_INVOKABLE void start();   // старт записи голосового фрагмента
    Q_INVOKABLE void stop();    // стоп записи голосового фрагмента

signals:

public slots:

private:
    QAudioRecorder* recorder_ = nullptr;
    static uint32_t counter_;
};

#endif // MOUSEMEMORY_H
