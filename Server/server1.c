#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 3000
#define BUFFER_SIZE 1024

void send_response(SOCKET client_socket, const char* status, const char* content_type, const char* content) {
    char response_header[512];
    sprintf(response_header, "HTTP/1.1 %s\r\nContent-Type: %s\r\n\r\n", status, content_type);
    send(client_socket, response_header, strlen(response_header), 0);
    send(client_socket, content, strlen(content), 0);
}

void handle_get_request(SOCKET client_socket, const char* request_path) {
    FILE* file = fopen(request_path, "rb");
    if (file == NULL) {
        const char* response_404 = "HTTP/1.1 404 Not Found\r\n\r\nFile Not Found";
        send_response(client_socket, "404 Not Found", "text/plain", response_404);
    } else {
        const char* content_type = "text/plain"; // Default content type
        if(strstr(request_path, ".html")) {
            content_type = "text/html";
        } else if(strstr(request_path, ".css")) {
            content_type = "text/css";
        } else if(strstr(request_path, ".js")) {
            content_type = "application/javascript";
        }

        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        while((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            send(client_socket, buffer, bytes_read, 0);
        }

        fclose(file);
    }

    closesocket(client_socket);
}

void handle_post_request(SOCKET client_socket, const char* request_path, const char* post_data) {
    // Implement POST request handling here
    // You can process the post_data and send an appropriate response
    // Example:
    const char* response_content = "This is a POST request response";
    send_response(client_socket, "200 OK", "text/plain", response_content);

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

        // Handle the request in a separate function
        char request_buffer[BUFFER_SIZE];
        size_t bytes_received = recv(client_socket, request_buffer, sizeof(request_buffer), 0);
        if(bytes_received > 0) {
            request_buffer[bytes_received] = '\0';

            // Parse the HTTP request to get the requested path
            const char* request_line = strtok(request_buffer, "\r\n");
            if(request_line != NULL) {
                const char* request_method = strtok(request_line, " ");
                const char* request_path = strtok(NULL, " ");

                if (request_method != NULL && request_path != NULL) {
                    if (strcmp(request_method, "GET") == 0) {
                        // Handle GET request based on the requested path
                        if(strcmp(request_path, "/") == 0) {
                            handle_get_request(client_socket, "index.html");
                        } else if(strcmp(request_path, "/index.js") == 0) {
                            handle_get_request(client_socket, "index.js");
                        } else if(strcmp(request_path, "/index.css") == 0) {
                            handle_get_request(client_socket, "index.css");
                        } else {
                            handle_get_request(client_socket, request_path);
                        }
                    } else if (strcmp(request_method, "POST") == 0) {
                        // Handle POST request based on the requested path and post data
                        // Extract post data from the request (assuming it's in the request body)
                        char* post_data_start = strstr(request_buffer, "\r\n\r\n");
                        if (post_data_start != NULL) {
                            post_data_start += 4; // Move past the empty line
                            handle_post_request(client_socket, request_path, post_data_start);
                        } else {
                            // Handle POST request without data (if needed)
                            // handle_post_request(client_socket, request_path, NULL);
                        }
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
