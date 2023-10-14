#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 3000
#define BUFFER_SIZE 1024

void handle_request(SOCKET client_socket, const char* request_path) {
    // Open and read the requested file
    FILE* file = fopen(request_path, "rb");
    if (file == NULL) {
        perror("File opening failed");
        const char* response_404 = "HTTP/1.1 404 Not Found\r\n\r\nFile Not Found";
        send(client_socket, response_404, strlen(response_404), 0);
    } else {
        // Determine the content type based on the file extension
        const char* content_type = "text/plain"; // Default content type
        if(strstr(request_path, ".html")) {
            content_type = "text/html";
        } else if(strstr(request_path, ".css")) {
            content_type = "text/css";
        } else if(strstr(request_path, ".js")) {
            content_type = "application/javascript";
        }

        // Send HTTP response header
        char response_header[512];
        sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n", content_type);
        send(client_socket, response_header, strlen(response_header), 0);

        // Send file content
        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        while((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            send(client_socket, buffer, bytes_read, 0);
        }

        fclose(file);
    }

    closesocket(client_socket);
}

int main() {
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == INVALID_SOCKET) {
        perror("Socket creation failed");
        WSACleanup();
        return 1;
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Socket binding failed");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Listen for connections
    if(listen(server_socket, 5) == SOCKET_ERROR) {
        perror("Socket listening failed");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while(1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        // sif(client_socket == INVALID_SOCKET) {
        //     perror("Connection accepting failed");
        //      continue;
        // }

        // Handle the request in a separate function
        char request_buffer[BUFFER_SIZE];
        size_t bytes_received = recv(client_socket, request_buffer, sizeof(request_buffer), 0);
        if(bytes_received > 0) {
            request_buffer[bytes_received] = '\0';

            // Parse the HTTP request to get the requested path
            const char* request_line = strtok(request_buffer, "\r\n");
            if(request_line != NULL) {
                const char* request_path = strtok(strstr(request_line, " ") + 1, " ");
                if(request_path != NULL) {
                    // Handle the request based on the requested path
                    if(strcmp(request_path, "/") == 0) {
                        // Serve index.html when URL is '/'
                        handle_request(client_socket, "index.html");
                    } else if(strcmp(request_path, "/index.js") == 0) {
                        handle_request(client_socket, "index.js");
                    } else if(strcmp(request_path, "/index.css") == 0) {
                        handle_request(client_socket, "index.css");
                    } else {
                        // Handle other files normally
                        handle_request(client_socket, request_path);
                    }
                }
            }
        }
    }

    // Close the server socket and clean up Winsock
    closesocket(server_socket);
    WSACleanup();

    return 0;
}