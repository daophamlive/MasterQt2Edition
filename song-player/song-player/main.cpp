#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "songlist.h"
#include "songmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qmlRegisterType<SongModel>("Song", 1, 0, "SongModel");
    qmlRegisterUncreatableType<SongList>("Song", 1, 0, "SongList", QStringLiteral("Song List in C++"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SongList songList;

    engine.rootContext()->setContextProperty(QStringLiteral("songList"), &songList);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
