#include "mousememory.h"
#include "phrases.h"
#include <QDebug>
#include <QDir>
#include <QStandardPaths>

uint32_t MouseMemory::counter_ = 0;

const char* get_timer_string(QString filename, int32_t seconds) {
    QString s;
    s.sprintf("%s %02d:%02d",
              filename.toStdString().c_str(), seconds / 60, seconds % 60);
    return s.toStdString().c_str();
}

MouseMemory::MouseMemory(QQmlContext* context, QObject* object, QObject *parent) : QObject(parent)
{
    context_ = context;

    recorder_ = new QAudioRecorder(this);
    timer_ = new QTimer(this);

    qml_record_text_ = object->findChild<QObject*>("qml_record_text");
    qml_timer_ = object->findChild<QObject*>("qml_timer");

    // проверка и создание директории для сохранения аудиозаписей
    dir_ = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation)[0] +
            QString("/VoiceRecorder");

    // если директория не существует, создадим её
    if (!QDir(dir_).exists()) {
        QDir().mkdir(dir_);
    }
}

void MouseMemory::start()
{
    qDebug() << "Start recording";

    qDebug() << recorder_->supportedAudioCodecs();
    // "amr-nb", "amr-wb", "aac"

    QAudioEncoderSettings audioSettings;
    audioSettings.setQuality(QMultimedia::VeryHighQuality);
    audioSettings.setChannelCount(1);
    audioSettings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
    audioSettings.setSampleRate(48000);

    recorder_->setAudioSettings(audioSettings);

    // QString file = "/sdcard/test" + QString::number(++counter_);
    QString file = dir_ + "/test" + QString::number(++counter_);
    recorder_->setOutputLocation(QUrl::fromLocalFile(file));
    recorder_->record();

    // установка текста, который должен прочитать пользователь
    uint32_t index = rand() % phrases.size();
    qml_record_text_->setProperty("text", phrases[index].c_str());

    // отображаем и сбрасываем в начальное состояние текст таймера
    qml_timer_->setProperty("text", get_timer_string(file, seconds_));
    qml_timer_->setProperty("visible", "true");

    connect(timer_, &QTimer::timeout, [=](){
        ++seconds_;
        qml_timer_->setProperty("text", get_timer_string(file, seconds_));
    });
    timer_->start(1000);
}

void MouseMemory::stop()
{
    qDebug() << "Stop recording";

    // выключение записи и таймера
    recorder_->stop();
    timer_->stop();
    seconds_ = 0;

    // сброс в начальное состояние qml-компонентов
    qml_record_text_->setProperty("text", "");
    qml_timer_->setProperty("visible", "false");
}
