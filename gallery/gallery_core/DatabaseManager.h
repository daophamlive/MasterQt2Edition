#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include "AlbumDao.h"

class QSqlDatabase;
const QString DATABASE_FILENAME = "gallery.db";


class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    explicit  DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* mDatabase;

public:
const AlbumDao mAlbumDao;
};

#endif // DATABASEMANAGER_H