#include "sampleclass.h"
#include <QDebug>

SampleClass::SampleClass()
{

}


void SampleClass::setValue(int _val)
{
        val = _val;
        emit valChanged(_val);
}


