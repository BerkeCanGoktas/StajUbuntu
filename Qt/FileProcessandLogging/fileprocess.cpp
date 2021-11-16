#include "fileprocess.h"
#include "exceptions.h"

FileProcess::FileProcess(QString filePath)
{
    m_filePath = filePath;

    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString txt = QString("[%1] ").arg(dt);
    QFile outFile("LogFile.log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream textStream(&outFile);
    textStream <<Qt::endl << "************" << txt << "***************" << Qt::endl << Qt::endl;

}

void FileProcess::writeFile(QString text){
    QFile file(this->m_filePath);
    try{
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QString err = exceptionHandler.m_writeFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_writeSuccess;
        throw err;
    }
    }
    catch(QString err){
        //this->exceptionHandler.MessageHandler()
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
    QTextStream out(&file);
    out << text;
    file.flush();
    file.close();
}

void FileProcess::readFile(){
    QFile file(this->m_filePath);
    try{
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QString err = exceptionHandler.m_readFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_readSuccess;
        throw err;
    }
    }
    catch(QString err){
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    qDebug() << text;

    file.close();
}


void FileProcess::appendFile(QString text){
    QFile file(this->m_filePath);
    try{
    if(!file.open(QFile::Append | QFile::Text)){
        QString err = exceptionHandler.m_appendFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_appendSuccess;
        throw err;
    }
    }
    catch(QString err){
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
    QTextStream out(&file);
    out << "/n" + text;
    file.flush();
    file.close();
}

void FileProcess::removeFile(){
    bool islemSonucu = QFile::remove(this->m_filePath);
    try{
    if(islemSonucu){
        QString err = exceptionHandler.m_removeFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_removeSuccess;
        throw err;
    }
    }
    catch(QString err){
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
}

void FileProcess::setFileName(QString newName){
    QString filePath = this->m_filePath;
    QStringList splittedPath = filePath.split("/");
    QString newFilePath = "";
    for(int i = 0; i< (splittedPath.size()-1); i++){
        newFilePath = newFilePath + splittedPath[i] + "/";
    }
    newFilePath = newFilePath + newName;
    bool islemSonucu = QFile::rename(this->m_filePath, newFilePath);
    try{
    if(islemSonucu){
        QString err = exceptionHandler.m_setFileNameFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_setFileNameSuccess;
        throw err;
    }
    }
    catch(QString err){
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
}

void FileProcess::createFile(QString newName, int permissions){
    QFile file(newName);
    bool islemSonucu = 1;
    try{
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QString err = exceptionHandler.m_writeFailExcp;
        throw err;
    }
    else{
        QString err = exceptionHandler.m_writeSuccess;
        throw err;
    }
    }
    catch(QString err){
        QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        QString txt = QString("[%1] ").arg(dt);
        QFile outFile("LogFile.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&outFile);
        txt += QString(" " + err);
        textStream << txt << Qt::endl;
        qDebug() << err << Qt::endl;
    }
    switch(permissions){
        case 0:
            break;
        case 1:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ExeUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 2:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::WriteUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 3:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ExeUser | QFileDevice::WriteUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 4:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ReadUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 5:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ExeUser | QFileDevice::ReadUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 6:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ReadUser | QFileDevice::WriteUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        case 7:
            islemSonucu = QFile::setPermissions(newName, QFileDevice::ExeUser | QFileDevice::ReadUser | QFileDevice::WriteUser);
            try{
            if(islemSonucu){
                QString err = exceptionHandler.m_setPermissionsFailExcp;
                throw err;
            }
            else{
                QString err = exceptionHandler.m_setPermissionsSuccess;
                throw err;
            }
            }
            catch(QString err){
                QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
                QString txt = QString("[%1] ").arg(dt);
                QFile outFile("LogFile.log");
                outFile.open(QIODevice::WriteOnly | QIODevice::Append);

                QTextStream textStream(&outFile);
                txt += QString(" " + err);
                textStream << txt << Qt::endl;
                qDebug() << err << Qt::endl;
            }
            break;
        default:
            qDebug() << "gecersiz izin";
            break;
    }

}
