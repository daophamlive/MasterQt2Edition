#include "person.h"

ShoeDescription::ShoeDescription(QObject *parent)
: QObject(parent), m_size(0), m_price(0)
{
}

int ShoeDescription::size() const
{
    return m_size;
}

void ShoeDescription::setSize(int s)
{
    m_size = s;
}

QColor ShoeDescription::color() const
{
    return m_color;
}

void ShoeDescription::setColor(const QColor &c)
{
    m_color = c;
}

QString ShoeDescription::brand() const
{
    return m_brand;
}

void ShoeDescription::setBrand(const QString &b)
{
    m_brand = b;
}

qreal ShoeDescription::price() const
{
    return m_price;
}

void ShoeDescription::setPrice(qreal p)
{
    m_price = p;
}

Person::Person(QObject *parent)
: QObject(parent)
{
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &n)
{
    m_name = n;
}

ShoeDescription *Person::shoe()
{
    return &m_shoe;
}

Boy::Boy(QObject * parent)
: Person(parent)
{
}

Girl::Girl(QObject * parent)
: Person(parent)
{
}
