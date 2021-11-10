#ifndef LISTENER_H
#define LISTENER_H
#include <QObject>
#include <QDebug>

class Listener: public QObject {
    Q_OBJECT
public:
    Listener();
signals:
public slots:
    void listen();
};

#endif // LISTENER_H
