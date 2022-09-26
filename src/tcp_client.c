#include "../cpp_directives/tcp_client.h"

int main(void)
{
    int network_sfd = socket(AF_INET, SOCK_STREAM, 0);
    int connection_status;
    char server_response[256];

    if (0 > network_sfd)
    {
        perror("socket()");
        exit(errno);
    }

    SA_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3443);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connection_status = connect(network_sfd, (SA *) &server_addr, sizeof(server_addr));
    if (-1 == connection_status)
    {
        perror("connect()");
        exit(errno);
    }

    recv(network_sfd, &server_response, sizeof(server_response), 0);
    printf("The server response: %s\n", server_response);
    close(network_sfd);
    return EXIT_SUCCESS;
}