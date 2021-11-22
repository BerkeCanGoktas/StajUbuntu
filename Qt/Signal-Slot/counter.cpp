#include "counter.h"

Counter::Counter()
{
    m_value = 0;
}

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}

int Counter::value() const {
return m_value;
}
