#ifndef MOUSEMEMORY_H
#define MOUSEMEMORY_H

#include <QObject>
#include <QDebug>
#include <QAudioRecorder>
#include <QUrl>
#include <QGuiApplication>
#include <QQmlContext>
#include <QTimer>

class MouseMemory : public QObject
{
    Q_OBJECT

public:
    explicit MouseMemory(QQmlContext* context, QObject* object, QObject *parent = 0);

    // Q_INVOKABLE - это макрос, который говорит, что функция должна вызываться из QML
    Q_INVOKABLE void start();   // старт записи голосового фрагмента
    Q_INVOKABLE void stop();    // стоп записи голосового фрагмента

signals:

public slots:

private:
    QAudioRecorder* recorder_ = nullptr;
    static uint32_t counter_;
    QQmlContext* context_ = nullptr;

    QTimer* timer_ = nullptr;
    int32_t seconds_ = 0;

    QObject* qml_record_text_ = nullptr;
    QObject* qml_timer_ = nullptr;
};

#endif // MOUSEMEMORY_H
