#include <QtCore>

// 3. Less than operator
bool operator<( const QPoint& p1, const QPoint& p2 )
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

bool isSubString(const QString &string) { return string.contains("hello"); }

/* An example of calculating a hash value. Not needed in the lab.
uint qHash( const QPoint& p )
{
    return qHash(p.x()) ^ qHash(p.y());
}
*/

int main( int argc, char** argv )
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);
	// 2. Create a container in stack
    QMap<QPoint, QString> container;

    // 4. Fill in the container
    QString item("Item ");
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            container.insert(QPoint(x, y), item + QString::number(100 * x + y));
        }
    }
    // 4. Print out the result with non-mutable iterator
    QMapIterator<QPoint, QString> iterator(container);
    while (iterator.hasNext()) {
        qDebug() << iterator.next().value();
    }

    // 5. Remove every third element from the container with mutable iterator
    QMutableMapIterator<QPoint, QString> mutableIterator(container);
    int count(1);
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 3) == 0) {
            mutableIterator.remove();
        }
    }
    // 5. Print out the result with the same mutable iterator
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        qDebug() << mutableIterator.next().value();
    }

    // 6. Set the value of every fifth element to hello n
    count = 1;
    QString hello("hello ");
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 5) == 0) {
            mutableIterator.setValue(hello + QString::number(count));
        }
    }

    // 7. Print out the result with c++11 ranged for loop
    for (const auto &item : container) {
        qDebug() << item;
    }

    // 8. Calculate how many times "hello" sub-string is included in the container
    qDebug() << std::count_if(container.begin(), container.end(), isSubString);
}
