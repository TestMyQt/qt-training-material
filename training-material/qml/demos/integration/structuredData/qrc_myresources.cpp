/****************************************************************************
** Resource object code
**
** Created: Tue Jul 3 10:19:31 2012
**      by: The Resource Compiler for Qt version 5.0.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/training/qml/StructuredData/main.qml
  0x0,0x0,0x0,0xc8,
  0x69,
  0x6d,0x70,0x6f,0x72,0x74,0x20,0x51,0x74,0x51,0x75,0x69,0x63,0x6b,0x20,0x32,0x2e,
  0x30,0xd,0xa,0xd,0xa,0x52,0x65,0x63,0x74,0x61,0x6e,0x67,0x6c,0x65,0x20,0x7b,
  0xd,0xa,0x20,0x20,0x20,0x20,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x32,0x30,0x30,
  0x3b,0x20,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x31,0x30,0x30,0xd,0xa,0x20,
  0x20,0x20,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x6d,0x79,0x42,0x61,0x63,0x6b,
  0x67,0x72,0x6f,0x75,0x6e,0x64,0x43,0x6f,0x6c,0x6f,0x72,0xd,0xa,0x20,0x20,0x20,
  0x20,0x54,0x65,0x78,0x74,0x20,0x7b,0xd,0xa,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
  0x20,0x61,0x6e,0x63,0x68,0x6f,0x72,0x73,0x2e,0x63,0x65,0x6e,0x74,0x65,0x72,0x49,
  0x6e,0x3a,0x20,0x70,0x61,0x72,0x65,0x6e,0x74,0xd,0xa,0x20,0x20,0x20,0x20,0x20,
  0x20,0x20,0x20,0x66,0x6f,0x6e,0x74,0x2e,0x70,0x69,0x78,0x65,0x6c,0x53,0x69,0x7a,
  0x65,0x3a,0x20,0x31,0x38,0xd,0xa,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x74,
  0x65,0x78,0x74,0x3a,0x20,0x6d,0x79,0x54,0x65,0x78,0x74,0xd,0xa,0x20,0x20,0x20,
  0x20,0x7d,0xd,0xa,0x7d,0xd,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // main.qml
  0x0,0x8,
  0x8,0x1,0x5a,0x5c,
  0x0,0x6d,
  0x0,0x61,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x71,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/main.qml
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_myresources)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_myresources))

int QT_MANGLE_NAMESPACE(qCleanupResources_myresources)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_myresources))
