#ifndef DATA_H
#define DATA_H

// 2.e.
//#include <QMetaType>

class QString;

class Data
{
public:
    Data();
    // Data object takes ownership of pointerArg pointer
    Data(int integerArg, int* pointerArg, const QString& stringArg);
    ~Data();
    void changeData(int int1, int *int2, const QString& string);

    int m_integer;
    int *m_pointer;
    QString m_string;
};

// 2.e.
//Q_DECLARE_METATYPE(Data);

#endif // DATA_H
