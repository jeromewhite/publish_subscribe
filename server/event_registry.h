#ifndef EVENTREGISTRY_H
#define EVENTREGISTRY_H

#include "Listener.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class EventRegistry
{
public:
    static void registerListener(string subject, Listener* inListener);
    static void handleMessage(string subject);
protected:
    static std::map<string, std::vector<Listener*> > sListenerMap;
};

#endif
