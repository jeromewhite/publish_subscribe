#include "Listener.h"
#include "event_registry.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

                                    // Subscription list for each message
map<string, vector<Listener*> > EventRegistry::sListenerMap;

void EventRegistry::registerListener(string subject, Listener* subscriber)
{
// Chapter 12 explains std::map. Note that if you specify a key
// using [] to access it, and there is not yet an entry in the map for
// that key, a new entry is created.
    sListenerMap[subject].push_back(subscriber);
}
void EventRegistry::handleMessage(string subject)
{
// Check to see if the message has *any* listeners. This check is required
// because otherwise, accessing sListenerMap[inMessage] would create
// a new entry when it’s not yet in the map. See Chapter 12.

//    map<int, vector<Listener*> >::iterator iter;
    vector<Listener*>::iterator iter;

    if (sListenerMap.find(subject) == sListenerMap.end())
        return;
    for (iter = sListenerMap[subject].begin();
        iter != sListenerMap[subject].end(); ++iter) {
        (*iter)->handleMessage(subject);
    }
}
