#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 4096

typedef struct {
    SOCKET socket;
} Server;

typedef struct {
    char method[16];
    char path[128];
} Request;

typedef struct {
    int status;
    const char *content_type;
    const char *body;
} Response;

Server createServer(int port);
Request parseRequest(SOCKET client_socket);
void sendResponse(SOCKET client_socket, Response res);
void closeServer(Server server);

Response readFile(const char *filename);
Response createResponse(int status, const char *content_type, const char *body);

#endif