#include <QAbstractListModel>
#include <QStringList>

class Animal 
{
public:
    Animal(const QString &type, const QString &size);

    QString type() const;
    QString size() const;

    void setType(const QString &type);
    void setSize(const QString &size);

private:
    QString m_type;
    QString m_size;
};

class AnimalModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    AnimalModel(QObject *parent = 0);

    void addAnimal(const Animal &animal);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Animal> m_animals;
};


