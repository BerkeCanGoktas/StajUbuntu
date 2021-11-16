#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include "fileprocess.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename = "/home/berke/Desktop/abc.txt";
    QString text = "deneme";
    QString name = "abcd.txt";
    QString newFileName = "/home/berke/Desktop/abcde.txt";
    QString append = "ekleme";
    FileProcess fileObj(filename);
    //qInstallMessageHandler((fileObj.exceptionHandler.MessageHandler));
    fileObj.writeFile(text);
    fileObj.readFile();
    fileObj.appendFile(append);
    fileObj.readFile();
    fileObj.setFileName(name);
    fileObj.createFile(newFileName, 6);
    //fileObj.removeFile();

    return a.exec();
}
