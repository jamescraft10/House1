#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Server createServer(int port) {
    Server server;
    struct sockaddr_in server_addr;

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        exit(1);
    }

    server.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket == INVALID_SOCKET) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server.socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Error binding");
        exit(1);
    }

    if (listen(server.socket, 10) == SOCKET_ERROR) {
        perror("Error listening");
        exit(1);
    }

    return server;
}

Request parseRequest(SOCKET client_socket) {
    char buffer[MAX_REQUEST_SIZE];
    Request req;

    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer) - 1, 0) == SOCKET_ERROR) {
        perror("Error reading request");
        exit(1);
    }

    sscanf(buffer, "%s %s", req.method, req.path);

    return req;
}

void sendResponse(SOCKET client_socket, Response res) {
    char response[MAX_REQUEST_SIZE];

    sprintf(response, "HTTP/1.1 %d OK\r\n", res.status);
    sprintf(response + strlen(response), "Content-Type: %s\r\n", res.content_type);
    sprintf(response + strlen(response), "Content-Length: %zu\r\n", strlen(res.body));
    strcat(response, "\r\n");
    strcat(response, res.body);

    if (send(client_socket, response, strlen(response), 0) == SOCKET_ERROR) {
        perror("Error writing response");
    }

    closesocket(client_socket);
}

void closeServer(Server server) {
    closesocket(server.socket);
    WSACleanup();
}

Response readFile(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Use "rb" mode for reading binary
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(file_size + 1);
    if (!content) {
        perror("Memory allocation error");
        exit(1);
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0';

    fclose(file);

    Response res;
    res.status = 200;
    res.content_type = "text/html"; // Default content type
    res.body = content;

    // Determine content type based on file extension
    if (strstr(filename, ".css")) {
        res.content_type = "text/css";
    } else if (strstr(filename, ".js")) {
        res.content_type = "application/javascript";
    }

    return res;
}

Response createResponse(int status, const char *content_type, const char *body) {
    Response res;
    res.status = status;
    res.content_type = content_type;
    res.body = body;

    return res;
}