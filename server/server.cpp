#include <iostream>

void Server::createSocket() {
    m_listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_listeningSocket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void Server::setSocketOptions() {
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
        sizeof(reuse_addr));
}

void Server::doBind() {
}

void Server::listen() {
    createSocket();
    setSocketOptions();
    doBind();
}

void Server::listen(int portNumber) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    /* So that we can re-bind to it without TIME_WAIT problems */
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
        sizeof(reuse_addr));

    /* Set socket to non-blocking with our setnonblocking routine */
    setnonblocking(sock);

    /* Get the address information, and bind it to the socket */
    ascport = argv[1]; /* Read what the user gave us */
    //port = atoport(ascport); /* Use function from sockhelp to
//                                    convert to an int */
    port = 8080;
    memset((char *) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &server_address,
      sizeof(server_address)) < 0 ) {
        perror("bind");
        close(sock);
        exit(EXIT_FAILURE);
    }
    /* Set up queue for incoming connections. */
    listen(sock,5);

}

Servee::waitForActivity() {
}
