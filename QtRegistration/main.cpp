#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>
#include "birthdayparty.h"
#include "person.h"

int main(int argc, char ** argv)
{
    QCoreApplication app(argc, argv);

    qmlRegisterType<BirthdayPartyAttached>();
    qmlRegisterType<BirthdayParty>("People", 1,0, "BirthdayParty");
    qmlRegisterType<ShoeDescription>();
    qmlRegisterType<Person>();
    qmlRegisterType<Boy>("People", 1,0, "Boy");
    qmlRegisterType<Girl>("People", 1,0, "Girl");

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:main.qml"));
    BirthdayParty *party = qobject_cast<BirthdayParty *>(component.create());

    if (party && party->host()) {
        qWarning() << party->host()->name() << "is having a birthday!";

        if (qobject_cast<Boy *>(party->host()))
            qWarning() << "He is inviting:";
        else
            qWarning() << "She is inviting:";

        for (int ii = 0; ii < party->guestCount(); ++ii) {
            Person *guest = party->guest(ii);

            QDate rsvpDate;
            QObject *attached =
                qmlAttachedPropertiesObject<BirthdayParty>(guest, false);
            if (attached)
                rsvpDate = attached->property("rsvp").toDate();

            if (rsvpDate.isNull())
                qWarning() << "   " << guest->name() << "RSVP date: Hasn't RSVP'd";
            else
                qWarning() << "   " << guest->name() << "RSVP date:" << qPrintable(rsvpDate.toString());
        }

        party->startParty();
    } else {
        qWarning() << component.errors();
    }

    return 0;
}
