#ifndef FILEPROCESS_H
#define FILEPROCESS_H

#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "exceptions.h"

class FileProcess
{
public:
    Exceptions exceptionHandler;
    void writeFile(QString text);
    void readFile();
    void appendFile(QString text);
    void removeFile();
    void createFile(QString newName, int permissions);
    void setFileName(QString newName);
    FileProcess(QString filePath);
private:
    QString m_filePath;
};

#endif // FILEPROCESS_H
