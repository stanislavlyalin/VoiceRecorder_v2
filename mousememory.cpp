#include "mousememory.h"
#include "phrases.h"

uint32_t MouseMemory::counter_ = 0;

MouseMemory::MouseMemory(QQmlContext* context, QObject *parent) : QObject(parent)
{
    context_ = context;
    recorder_ = new QAudioRecorder(this);
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

    QString file = "/sdcard/test" + QString::number(++counter_);
    recorder_->setOutputLocation(QUrl::fromLocalFile(file));
    recorder_->record();

    uint32_t index = rand() % phrases.size();
    context_->setContextProperty("hint_text", phrases[index].c_str());
}

void MouseMemory::stop()
{
    qDebug() << "Stop recording";

    recorder_->stop();
    context_->setContextProperty("hint_text", "");
}
