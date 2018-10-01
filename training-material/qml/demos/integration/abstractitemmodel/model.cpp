#include "model.h"

Animal::Animal(const QString &type, const QString &size)
    : m_type(type), m_size(size)
{
}

QString Animal::type() const
{
    return m_type;
}

QString Animal::size() const
{
    return m_size;
}

void Animal::setType(const QString &type)
{
    m_type = type;
}

void Animal::setSize(const QString &size)
{
    m_size = size;
}

AnimalModel::AnimalModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void AnimalModel::addAnimal(const Animal &animal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_animals << animal;
    endInsertRows();
}

int AnimalModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent)
    return m_animals.count();
}

Qt::ItemFlags AnimalModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

bool AnimalModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() > m_animals.count())
        return false;

    Animal &animal = m_animals[index.row()];
    if (role == TypeRole || role == Qt::EditRole)
        animal.setType(value.toString());
    else if (role == SizeRole)
        animal.setSize(value.toString());
    m_animals[index.row()] = animal;
    Q_EMIT dataChanged(index, index);
    return true;
}

QVariant AnimalModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_animals.count())
        return QVariant();

    const Animal &animal = m_animals[index.row()];
    if (role == TypeRole || role == Qt::DisplayRole)
        return animal.type();
    else if (role == SizeRole)
        return animal.size();
    return QVariant();
}

QHash<int, QByteArray> AnimalModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}


