#include "songlist.h"

SongList::SongList(QObject *parent) : QObject(parent)
{
    mSongItems.append( { QStringLiteral("Song 1"), QStringLiteral("Author 1"), QStringLiteral("215MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
    mSongItems.append( { QStringLiteral("Song 5"), QStringLiteral("Author 3"), QStringLiteral("3.5MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
    mSongItems.append( { QStringLiteral("Song 6"), QStringLiteral("Author 6"), QStringLiteral("4.5MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
    mSongItems.append( { QStringLiteral("Song 8"), QStringLiteral("Author 4"), QStringLiteral("8.5MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
    mSongItems.append( { QStringLiteral("Song 2"), QStringLiteral("Author 4"), QStringLiteral("9.5MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
    mSongItems.append( { QStringLiteral("Song 4"), QStringLiteral("Author 3"), QStringLiteral("2.5MB"), QStringLiteral("/songs/"), QStringLiteral("2:34"), false } );
}

bool SongList::setItemAt(int index, const SongItem &item)
{
    if(index < 0 || index >= mSongItems.size())
        return false;

    const SongItem &oldItem = mSongItems.at(index);
    if (&item == &oldItem)
        return false;

    mSongItems[index] = item;
    return true;
}

QVector<SongItem> SongList::getItems() const
{
    return mSongItems;
}

void SongList::appendItem()
{
    emit preItemAppended();

    SongItem song;
    song.name = QStringLiteral("Unknown");
    song.author = QStringLiteral("Unknown");
    song.size = QStringLiteral("Unknown");
    song.selected = false;
    song.duration = QStringLiteral("0:0");
    song.path = QStringLiteral("");
    mSongItems.append(song);

    emit postItemAppended();
}

void SongList::removeCompletedItems()
{
    for (int i = 0; i < mSongItems.size(); ) {
       if(mSongItems[i].selected)
       {
           emit preItemRemoved(i);
           mSongItems.removeAt(i);
           emit postItemRemoved();
       }
       else
       {
           i++;
       }
    }
}

void SongList::setSelectedItem(int index, bool isSelected)
{
    if(index < 0 || index >= mSongItems.size())
        return false;

    SongItem &item = mSongItems[index];
    item.selected = isSelected;
}

void SongList::setSelectedItem(bool isSelected)
{
    foreach (SongItem item, mSongItems) {
        item.selected = isSelected;
    }
}
