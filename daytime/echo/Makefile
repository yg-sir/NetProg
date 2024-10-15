# Названия исполняемых файлов
SERVER = server
CLIENT = client

# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Исходные файлы
SERVER_SRC = server.cpp
CLIENT_SRC = client.cpp

# Правила сборки
all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC)
	$(CXX) $(CXXFLAGS) -o $(SERVER) $(SERVER_SRC)

$(CLIENT): $(CLIENT_SRC)
	$(CXX) $(CXXFLAGS) -o $(CLIENT) $(CLIENT_SRC)

# Очистка скомпилированных файлов
clean:
	rm -f $(SERVER) $(CLIENT)
