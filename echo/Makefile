# Название исполняемого файла
TARGET = echo

# Компилятор
CC = g++

# Флаги компиляции
CFLAGS = -Wall -Wextra

# Исходные файлы
SRCS = echo.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию для сборки
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для компиляции объектных файлов
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки
clean:
	rm -f $(OBJS) $(TARGET)

	.PHONY: all clean
