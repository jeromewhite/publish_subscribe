#ifndef LISTENER_H
#define LISTENER_H

#include <stdio.h>
#include <string>

using namespace std;

class Listener
{
public:
    virtual void handleMessage(string subject) = 0;
                        // Retrived from the return address of the packet
    FILE *fd;
};

#endif
