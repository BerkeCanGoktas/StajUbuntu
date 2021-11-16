#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <QFile>

class Exceptions
{
public:
    Exceptions();
    QString m_writeFailExcp = "Dosya yazmak icin acilamadi";
    QString m_writeSuccess = "Dosya yazmak icin acildi";
    QString m_readFailExcp = "Dosya okumak icin acilamadi";
    QString m_readSuccess = "Dosya okumak icin acildi";
    QString m_appendFailExcp = "Dosya ekleme yapmak icin acilamadi";
    QString m_appendSuccess = "Dosya ekleme yapmak icin acildi";
    QString m_removeFailExcp = "Dosya silinemedi";
    QString m_removeSuccess = "Dosya silindi";
    QString m_setFileNameFailExcp = "Dosya adi degistirilemedi";
    QString m_setFileNameSuccess = "Dosya adi degistirildi";
    QString m_createFailExcp = "Dosya olusturulamadi";
    QString m_createSuccess = "Dosya olusturuldu";
    QString m_setPermissionsFailExcp = "Izinler atanirken bir hata olustu";
    QString m_setPermissionsSuccess = "Izinler atandi";
    void static MessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

#endif // EXCEPTIONS_H
