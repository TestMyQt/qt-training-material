#include <QString>
#include "data.h"

Data::Data() :
    m_integer(-1), m_pointer(0), m_string()
{
}

Data::Data(int integerArg, int *pointerArg, const QString &stringArg) :
    m_integer(integerArg), m_pointer(pointerArg), m_string(stringArg)
{
}

Data::~Data()
{
    if (m_pointer)
        delete m_pointer;
}

void Data::changeData(int int1, int *int2, const QString &string)
{
    m_integer = int1;
    if (m_pointer) {
        delete m_pointer;
        m_pointer = int2;
    }
    m_string = string;
}

