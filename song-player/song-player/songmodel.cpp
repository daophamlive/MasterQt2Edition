#include "songmodel.h"
#include "songlist.h"
SongModel::SongModel(QObject *parent)
    : QAbstractListModel(parent)
    , mSongList(nullptr)
{
}

QVariant SongModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);
    return QVariant();
}

bool SongModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int SongModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return mSongList->getItems().size();
}

QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const SongItem &itemData = mSongList->getItems().at(index.row());
    switch (role) {
    case NameRole:
        return QVariant(itemData.name);
        break;
    case AuthorRole:
        return QVariant(itemData.author);
        break;
    case SizeRole:
        return QVariant(itemData.size);
        break;
    case PathRole:
        return QVariant(itemData.path);
        break;
    case DurationRole:
        return QVariant(itemData.duration);
        break;
    case SelectedRole:
        return QVariant(itemData.selected);
        break;
    default:
        break;
    }
    return QVariant();
}

bool SongModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mSongList)
        return false;
    SongItem itemData = mSongList->getItems().at(index.row());

    switch (role) {
    case NameRole:
        itemData.name = value.toString();
        break;
    case AuthorRole:
        itemData.author = value.toString();
        break;
    case SizeRole:
        itemData.size = value.toString();
        break;
    case PathRole:
        itemData.path = value.toString();
        break;
    case DurationRole:
        itemData.duration = value.toString();
        break;
    case SelectedRole:
        itemData.selected = value.toBool();
        break;
    default:
        break;
    }
    if (mSongList->setItemAt(index.row(), itemData)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags SongModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

bool SongModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}

bool SongModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> SongModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AuthorRole] = "author";
    roles[SizeRole] = "size";
    roles[DurationRole] = "duration";
    roles[PathRole] = "path";
    roles[SelectedRole] = "selected";
    return roles;
}

SongList *SongModel::getSongList() const
{
    return mSongList;
}

void SongModel::setSongList(SongList *value)
{
    beginResetModel();
    if(mSongList)
        mSongList->disconnect(this);

    mSongList = value;

    if(mSongList)
    {
        connect(mSongList, &SongList::preItemAppended, [=](){
            const int index = mSongList->getItems().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mSongList, &SongList::postItemAppended, [=](){
            endInsertRows();
        });

        connect(mSongList, &SongList::preItemRemoved, [=](int index){
            beginRemoveRows(QModelIndex(), index, index);
        });

        connect(mSongList, &SongList::postItemRemoved, [=](){
            endRemoveRows();
        });

        connect(mSongList, &SongList::un)

    }

    endResetModel();
}
