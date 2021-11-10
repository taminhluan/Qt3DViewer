#ifndef SPEACKER_H
#define SPEACKER_H
#include <QObject>
#include <QDebug>

class Speacker: public QObject {
    Q_OBJECT
public:
    Speacker();
signals:
    void speak();
public slots:

};

#endif // SPEACKER_H
