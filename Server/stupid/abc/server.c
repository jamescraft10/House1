#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define MAX_CLIENTS 10

void send_message_to_all(char *message, SOCKET *client_sockets, int max_clients, SOCKET current_socket) {
    for (int i = 0; i < max_clients; i++) {
        SOCKET client_socket = client_sockets[i];

        if (client_socket != 0 && client_socket != current_socket) {
            send(client_socket, message, strlen(message), 0);
        }
    }
}

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_sockets[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize WinSock2\n");
        return 1;
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        printf("Error creating server socket\n");
        WSACleanup();
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Error binding server socket\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == SOCKET_ERROR) {
        printf("Error listening for connections\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Server is running on port %d...\n", PORT);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        int max_socket = server_socket;

        for (int i = 0; i < MAX_CLIENTS; i++) {
            SOCKET client_socket = client_sockets[i];

            if (client_socket != 0) {
                FD_SET(client_socket, &read_fds);
                if (client_socket > max_socket) {
                    max_socket = client_socket;
                }
            }
        }

        int activity = select(0, &read_fds, NULL, NULL, NULL);

        if (activity == SOCKET_ERROR) {
            printf("Error in select\n");
            break;
        }

        if (FD_ISSET(server_socket, &read_fds)) {
            SOCKET new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
            if (new_client_socket == INVALID_SOCKET) {
                printf("Error accepting connection\n");
            } else {
                // Add new client socket to the array
                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (client_sockets[i] == 0) {
                        client_sockets[i] = new_client_socket;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            SOCKET client_socket = client_sockets[i];

            if (FD_ISSET(client_socket, &read_fds)) {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));

                int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

                if (bytes_received <= 0) {
                    // Connection closed or error
                    closesocket(client_socket);
                    client_sockets[i] = 0;
                } else {
                    // Handle the received message
                    buffer[bytes_received] = '\0';  // Null-terminate the received data
                    printf("Received: %s\n", buffer);

                    // Broadcast the message to all connected clients
                    send_message_to_all(buffer, client_sockets, MAX_CLIENTS, client_socket);
                }
            }
        }
    }

    // Close all client sockets and the server socket
    for (int i = 0; i < MAX_CLIENTS; i++) {
        SOCKET client_socket = client_sockets[i];
        if (client_socket != 0) {
            closesocket(client_socket);
        }
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}