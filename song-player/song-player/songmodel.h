#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QAbstractListModel>


class SongList;
class SongModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(SongList *mSongList READ getSongList WRITE setSongList)
public:
    explicit SongModel(QObject *parent = nullptr);



//    name: "Hanh phuc xa roi"
//    author: "Dao"
//    size: "3.5MB"
//    selected: false
    enum{
        NameRole = Qt::UserRole,
        AuthorRole,
        SizeRole,
        DurationRole,
        PathRole,
        SelectedRole
    };


    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    SongList *getSongList() const;
    void setSongList(SongList *value);

private:
    SongList *mSongList;
};

#endif // SONGMODEL_H
