#include "../cpp_directives/tcp_server.h"

int main(void)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    int client_socket;
    char server_response[25] = "Successfully connected";

    if (0 > sfd)
    {
        perror("socket()");
        exit(errno);
    }

    SA_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3443);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sfd, (SA *) &addr, sizeof(addr));

    listen(sfd, 5);

    client_socket = accept(sfd, NULL, NULL);
    send(client_socket, server_response, sizeof(server_response), 0);
    close(client_socket);
    close(sfd);
    return 0;
}