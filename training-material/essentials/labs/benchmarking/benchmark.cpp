#include <QString>

bool operator<( const QPoint& p1, const QPoint& p2 )
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

int main(int argc, char **argv)
{
    QMap<QPoint, QString> container;
    QString stringHolder;

    QString item("Item ");
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            container.insert( QPoint( x, y), item + QString::number( 100 * x + y ));
        }
    }

    // Iterate the items using non-mutable iterator
    QMapIterator<QPoint, QString> iterator1(container);
    while (iterator1.hasNext()) {
        stringHolder = iterator1.next().value();
    }

    // Iterate the items using const STL iterator
    QMap<QPoint, QString>::const_iterator iterator2;
    iterator2 = container.begin();
    while (iterator2 != container.end()) {
        stringHolder2 = *iterator2++;
    }

    // Iterate the items using Q_FOREACH
    Q_FOREACH(const QString &item, container) {
        stringHolder = item;
    }

    // Iterate the items using mutable iterator
    QMutableMapIterator<QPoint, QString> iterator3(container);
    while (iterator3.hasNext()) {
        iterator3.setValue("New value");
        iterator3.next();
    }

    // Iterate the items using non_const STL iterator
    QMap<QPoint, QString>::iterator iterator4;
    iterator4 = container.begin();
    while (iterator4 != container.end()) {
        *iterator4++ = "New value";
    }
}
