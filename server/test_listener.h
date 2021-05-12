#include "listener.h"

class TestListener : public Listener {
public:
    TestListener();
    void handleMessage(int inMessage);
    bool bMessage0Received;
    bool bUnknownMessageReceived;
};


