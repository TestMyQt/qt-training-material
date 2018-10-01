#ifndef DATA_H
#define DATA_H

class QString;

class Data
{
public:
    Data();
    Data(int integerArg, int* pointerArg, const QString& stringArg);
    ~Data();
    void changeData(int int1, int *int2, const QString& string);

    int m_integer;
    int *m_pointer;
    QString m_string;
};

#endif // DATA_H
