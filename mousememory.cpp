#include "mousememory.h"

uint32_t MouseMemory::counter_ = 0;

MouseMemory::MouseMemory(QObject *parent) : QObject(parent)
{
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
}

void MouseMemory::stop()
{
    qDebug() << "Stop recording";

    recorder_->stop();
}
