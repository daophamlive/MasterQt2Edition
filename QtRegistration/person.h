#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QColor>

class ShoeDescription : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int size READ size WRITE setSize)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QString brand READ brand WRITE setBrand)
    Q_PROPERTY(qreal price READ price WRITE setPrice)
public:
    ShoeDescription(QObject *parent = 0);

    int size() const;
    void setSize(int);

    QColor color() const;
    void setColor(const QColor &);

    QString brand() const;
    void setBrand(const QString &);

    qreal price() const;
    void setPrice(qreal);
private:
    int m_size;
    QColor m_color;
    QString m_brand;
    qreal m_price;
};

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(ShoeDescription *shoe READ shoe)
public:
    Person(QObject *parent = 0);

    QString name() const;
    void setName(const QString &);

    ShoeDescription *shoe();
private:
    QString m_name;
    ShoeDescription m_shoe;
};

class Boy : public Person
{
    Q_OBJECT
public:
    Boy(QObject * parent = 0);
};

class Girl : public Person
{
    Q_OBJECT
public:
    Girl(QObject * parent = 0);
};

#endif // PERSON_H
