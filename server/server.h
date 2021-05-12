class Server {
public:
    Server(int portNumber);
    virtual void onSelect() = 0;
    void    listen();
    void    listen(int portNumber);
    virtual void onError();
    virtual void onDisconnect();
    int     waitForActivity();

protected:
    EventRegistry       *eventRegiser;
    void    setupListenPort();
    void    setnonblocking();
    void    create
private:
    int     m_portNum;
    fd_set  m_socketTable; 
    socket  m_listeningSocket;
    int     m_connectList[20];

}

