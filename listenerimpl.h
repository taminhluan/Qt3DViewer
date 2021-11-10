#ifndef LISTENERIMPL_H
#define LISTENERIMPL_H

#include "Listener.h"

class ListenerImpl: public Listener
{
public:
    ListenerImpl();
public slots:
    void listenImpl();
};

#endif // LISTENERIMPL_H
