# makefile for "Game Engine" project
PROJ_NAME = GameEngine

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

# Source files
C_SOURCES = $(wildcard ./src/*.c)
H_SOURCES = $(wildcard ./src/*.h)

# Object files
OBJ = $(C_SOURCES:.c=.o)



# Main target
$(PROJ_NAME): objFolder $(OBJ)
	@ echo "Building \"$(PROJ_NAME)\""







# objects folder
objFolder:
	@ echo "Creating /obj"
	mkdir -p obj


clean:
	@ echo "Cleaning up (delete /obj and \"$(PROJ_NAME).exe\")"
	rm -rf obj
	rm -f $(PROJ_NAME).exe
