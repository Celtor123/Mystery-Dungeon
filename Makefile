# Nombre del ejecutable final
TARGET = programa
# Archivos fuente
SRCS = mazmorra.c main.c
# Compilador
CC=gcc
# flags de SDL2 (obtiene automaticamente los include y librerias)
SDL_FLAGS = $(shell sdl2-config --cflags --libs)
# Compila y genera el ejecutable
all:
	$(CC) $(SRCS) -o $(TARGET) $(SDL_FLAGS) -g
# Limpiar los archivos generados
clean:
	rm -f $(TARGET)
# Compilar y ejecutar de una vez
run: all
	./$(TARGET)
