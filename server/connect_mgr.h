class   connectionManager {
public:
    connect_mgr(int portNum);
    virtual void onSelect() = 0;
    virtual void onError();
    virtual void onDisconnect();
    int     waitForActivity();
//    void    waitForConnection();
//    void    waitForConnection(int portNum);

protected:
    void    setupListenPort();
    void    setnonblocking();
private:
    int     m_portNum;
    fd_set  m_socketTable;
    socket  m_listeningSocket;
    int     m_connectList[20];
}
