#include <QString>
#include <QtTest>

bool operator<( const QPoint& p1, const QPoint& p2 )
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

QMap<QPoint, QString> container;
QString stringHolder;

class Container_perfTest : public QObject
{
    Q_OBJECT

public:
    Container_perfTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
    void testCase5();
};

Container_perfTest::Container_perfTest()
{
}

void Container_perfTest::initTestCase()
{
    QString item("Item ");
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            container.insert( QPoint( x, y), item + QString::number( 100 * x + y ));
        }
    }
}

void Container_perfTest::cleanupTestCase()
{
}

void Container_perfTest::testCase1()
{
    QMapIterator<QPoint, QString> iterator(container);
    QBENCHMARK {
        iterator.toFront();
        while (iterator.hasNext()) {
            stringHolder = iterator.next().value();
        }
    }
}

void Container_perfTest::testCase2()
{
    QMap<QPoint, QString>::const_iterator iterator;
    QBENCHMARK {
        iterator = container.begin();
        while (iterator != container.end()) {
            stringHolder = *iterator++;
        }
    }
}

void Container_perfTest::testCase3()
{
    QBENCHMARK {
        Q_FOREACH(const QString &item, container) {
            stringHolder = item;
        }
    }
}

void Container_perfTest::testCase4()
{
    QMutableMapIterator<QPoint, QString> iterator(container);
    QBENCHMARK {
        iterator.toFront();
        while (iterator.hasNext()) {
            iterator.setValue("New value");
            iterator.next();
        }
    }
}

void Container_perfTest::testCase5()
{
    QMap<QPoint, QString>::iterator iterator;
    QBENCHMARK {
        iterator = container.begin();
        while (iterator != container.end()) {
            *iterator++ = "New value";
        }
    }
}

QTEST_APPLESS_MAIN(Container_perfTest)

#include "tst_container_perftest.moc"
