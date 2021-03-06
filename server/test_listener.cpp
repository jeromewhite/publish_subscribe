#include "event_registry.h"
#include "test_listener.h"

TestListener::TestListener() : bMessage0Received(false), bUnknownMessageReceived(false)
{
// Subscribe to event 0.
    EventRegistry::registerListener(0, this);
}

void TestListener::handleMessage(int inMessage)
{
    switch (inMessage) {
        case 0:
        bMessage0Received = true;
        break;
        default:
        bUnknownMessageReceived = true;
        break;
    }
}
