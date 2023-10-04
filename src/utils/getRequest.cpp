#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include <ostream>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

std::string getRequest(const std::string url) {
    const char* host = url.c_str();
    const char* path = "/";
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error with socket");
        return "1";
    }
    struct hostent* server = gethostbyname(host);
    if (server == nullptr) {
        perror("Error with DNS");
        close(sockfd);
        return "1";
    }
    struct sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error with server connection");
        close(sockfd);
        return "1";
    }
    std::ostringstream request_stream;
    request_stream << "GET " << path << " HTTP/1.1\r\n";
    request_stream << "Host: " << host << "\r\n";
    request_stream << "Connection: close\r\n";
    request_stream << "\r\n";
    std::string request = request_stream.str();
    if (send(sockfd, request.c_str(), request.size(), 0) == -1) {
        perror("Error with request sending");
        close(sockfd);
        return "1";
    }
    char buffer[1024];
    std::string response;
    while (true) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        response.append(buffer, bytes_received);
    }
    return response;
}