#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h>

#define PORT 44214

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Ошибка создания сокета" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "172.16.40.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Неверный адрес" << std::endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Ошибка подключения" << std::endl;
        return -1;
    }

    while (true) {
        std::string message;
        std::cout << "Введите сообщение для отправки (или 'exit' для выхода): ";
        std::getline(std::cin, message);
        
        if (message == "exit") break;

        ssize_t sent_bytes = send(sock, message.c_str(), message.size(), 0);
        if (sent_bytes < 0) {
            std::cerr << "Ошибка отправки сообщения" << std::endl;
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        int valread = read(sock, buffer, sizeof(buffer) - 1); 
        if (valread < 0) {
            std::cerr << "Ошибка чтения ответа от сервера" << std::endl;
            break;
        }

        std::cout << "Получено от сервера: " << std::string(buffer, valread) << std::endl;
    }

    close(sock);
    return 0;
}
