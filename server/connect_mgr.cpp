connectionManager::connectionManager(int portNum) {
    m_portNum = portNum;
}

connectionManager::connet_mgr() {
}

connectionManager::onError() {
}

connectionManager::onDisconnect() {
}

/*
connectionManager::waitForConnection() {
    select();
}
*/

connectionManager::waitForActivity() {

    while(1) {
        int nActiveSockets;

        build_select_list();
        nActiveSockets = select(highsock+1, &socks, (fd_set *) 0, (fd_set *) 0, &timeout);
        if (nActiveSockets < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }
        if (nActiveSockets == 0) {
            /* Nothing ready to read, just show that
               we're alive */
            printf(".");
            fflush(stdout);
        } else
            read_socks();

    }
}

void connectionManager::setupListenPort() {
}

void connectionManager::build_select_list() {
    int listnum;         /* Current item in connectlist for for loops */

    /* First put together fd_set for select(), which will
       consist of the sock veriable in case a new connection
       is coming in, plus all the sockets we have already
       accepted. */


    /* FD_ZERO() clears out the fd_set called socks, so that
        it doesn't contain any file descriptors. */

    FD_ZERO(&socks);

    /* FD_SET() adds the file descriptor "sock" to the fd_set,
        so that select() will return if a connection comes in
        on that socket (which means you have to do accept(), etc. */

    FD_SET(sock,&socks);

    /* Loops through all the possible connections and adds
        those sockets to the fd_set */

    for (listnum = 0; listnum < 5; listnum++) {
        if (connectlist[listnum] != 0) {
            FD_SET(connectlist[listnum],&socks);
            if (connectlist[listnum] > highsock)
                highsock = connectlist[listnum];
        }
    }
}

