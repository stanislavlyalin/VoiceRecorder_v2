#include "mousememory.h"

MouseMemory::MouseMemory(QObject *parent) : QObject(parent)
{
    recorder_ = new QAudioRecorder(this);
}

void MouseMemory::start()
{
    qDebug() << "Start recording";
}

void MouseMemory::stop()
{
    qDebug() << "Stop recording";
}
