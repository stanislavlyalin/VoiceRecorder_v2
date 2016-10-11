#include <QGuiApplication>
#include <QQmlApplicationEngine>

// эти 2 строки нужны для взаимодействия QML-кода с кодом на C++
#include <QQmlEngine>
#include <QQmlContext>
#include "mousememory.h"    // подключаем класс с кодом C++

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    // умный указатель на класс, который мы хотим сделать доступным в QML
    QScopedPointer<MouseMemory> mouse(new MouseMemory(engine.rootContext()));

    // делаем объект mouse доступным в QML под именем "mouse"
    engine.rootContext()->setContextProperty("mouse", mouse.data());
    engine.rootContext()->setContextProperty("hint_text", "");

    return app.exec();
}
