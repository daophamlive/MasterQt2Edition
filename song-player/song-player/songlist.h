#ifndef SONGLIST_H
#define SONGLIST_H

#include <QObject>
#include <QVector>

struct SongItem
{
    QString name;
    QString author;
    QString size;
    QString path;
    QString duration;
    bool selected;

    bool operator== (const SongItem &item)
    {
        bool isTheSame = false;

        if(this->name == item.name
                && this->author == item.author
                && this->size == item.size
                && this->path == item.path
                && this->duration == item.duration)
            isTheSame = true;

        return isTheSame;
    }

};

class SongList : public QObject
{
    Q_OBJECT
public:
    explicit SongList(QObject *parent = nullptr);

    bool setItemAt(int index, const SongItem &item);

    QVector<SongItem> getItems() const;

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItems();
    void setSelectedItem(int index, bool isSelected);
    void setSelectedItem(bool isSelected);
private:
    QVector<SongItem> mSongItems;
};

#endif // SONGLIST_H
