#ifndef BIRTHDAYPARTY_H
#define BIRTHDAYPARTY_H

#include <QObject>
#include <QDate>
#include <qqml.h>
#include "person.h"

class BirthdayPartyAttached : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDate rsvp READ rsvp WRITE setRsvp)
public:
    BirthdayPartyAttached(QObject *object);

    QDate rsvp() const;
    void setRsvp(const QDate &);

private:
    QDate m_rsvp;
};

class BirthdayParty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Person *host READ host WRITE setHost)
    Q_PROPERTY(QQmlListProperty<Person> guests READ guests)
    Q_CLASSINFO("DefaultProperty", "guests")
public:
    BirthdayParty(QObject *parent = 0);

    Person *host() const;
    void setHost(Person *);

    QQmlListProperty<Person> guests();
    int guestCount() const;
    Person *guest(int) const;

    static BirthdayPartyAttached *qmlAttachedProperties(QObject *);

    void startParty();
// ![0]
signals:
    void partyStarted(const QTime &time);
// ![0]

private:
    Person *m_host;
    QList<Person *> m_guests;
};
QML_DECLARE_TYPEINFO(BirthdayParty, QML_HAS_ATTACHED_PROPERTIES)

#endif // BIRTHDAYPARTY_H
