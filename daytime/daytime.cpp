#include <iostream>
#include <cstring>      
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>    
#include <netinet/in.h> 

#define DAYTIME_PORT 44214 
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Ошибка при создании сокета." << std::endl;
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(44214);
    server_addr.sin_addr.s_addr = inet_addr("172.16.40.1"); 

    const char *request = "GET TIME";
    if (sendto(sockfd, request, strlen(request), 0, 
               (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Ошибка при отправке данных." << std::endl;
        close(sockfd);
        return 1;
    }

    socklen_t addr_len = sizeof(server_addr);
    ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, 
                         (struct sockaddr*)&server_addr, &addr_len);
    
    if (n < 0) {
        std::cerr << "Ошибка при получении данных." << std::endl;
        close(sockfd);
        return 1;
    }

    buffer[n] = '0'; 
    std::cout << "Ответ от сервера: " << buffer << std::endl;

    close(sockfd);
    return 0;
}
