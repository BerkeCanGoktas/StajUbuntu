#ifndef SAMPLECLASS_H
#define SAMPLECLASS_H

#include <QObject>

class SampleClass: public QObject
{
    Q_OBJECT

public:
    SampleClass();

private:
    int val;

public slots:
    void setValue(int _val);

signals:
    void valChanged(int nVal);
};

#endif // SAMPLECLASS_H
