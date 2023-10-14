#include "server.h"
#include <stdio.h>

int main() {
    Server server = createServer(PORT);
    printf("Server is running on port %d...\n", PORT);

    while (1) {
        SOCKET client_socket;
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        client_socket = accept(server.socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == INVALID_SOCKET) {
            perror("Error accepting connection");
            continue;
        }

        Request req = parseRequest(client_socket);

        // Handle requests based on the path
        if (strcmp(req.path, "/") == 0) {
            Response res = readFile("index.html");
            sendResponse(client_socket, res);
        } else if (strcmp(req.path, "/index.css") == 0) {
            Response res = readFile("index.css");
            sendResponse(client_socket, res);
        } else if (strcmp(req.path, "/index.js") == 0) {
            Response res = readFile("index.js");
            sendResponse(client_socket, res);
        } else if (strcmp(req.path, "/other_route") == 0) {
            // Handle other routes here
            Response res = createResponse(200, "text/plain", "This is another route.");
            sendResponse(client_socket, res);
        } else {
            Response res = createResponse(404, "text/plain", "Not Found");
            sendResponse(client_socket, res);
        }
    }

    closeServer(server);

    return 0;
}