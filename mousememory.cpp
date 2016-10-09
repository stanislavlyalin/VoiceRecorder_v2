#include "mousememory.h"

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
    audioSettings.setCodec("audio/amr-nb");
    audioSettings.setQuality(QMultimedia::HighQuality);
    audioSettings.setChannelCount(1);

    recorder_->setAudioSettings(audioSettings);

    //QString file = QCoreApplication::applicationDirPath() + "/test.amr";
    QString file = "/sdcard/test";
    recorder_->setOutputLocation(QUrl::fromLocalFile(file));
    recorder_->record();
}

void MouseMemory::stop()
{
    qDebug() << "Stop recording";

    recorder_->stop();
}
