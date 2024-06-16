# makefile for "Game Engine" project
PROJ_NAME = GameEngine

# main file
MAIN_NAME = main


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

# Source files
C_SOURCES = $(wildcard ./src/*.c)
H_SOURCES = $(wildcard ./src/*.h)

# Object files (replace .c with .o and src with obj)
OBJ = $(patsubst ./src/%.c, ./obj/%.o, $(C_SOURCES))



# Main target
$(PROJ_NAME): objFolder $(OBJ)
	@ echo "-> Building \"$(PROJ_NAME)\""
	$(CC) $(OBJ) -o $(PROJ_NAME).exe


# Compile object files (*.c and *.h -> *.o) (main.c does not have a header file)
./obj/%.o: ./src/%.c ./src/%.h
	@ echo "-> Compiling \"$<\" to \"$@\""
	$(CC) $(CFLAGS) -c $< -o $@

./obj/$(MAIN_NAME).o: ./src/$(MAIN_NAME).c
	@ echo "-> Compiling \"$<\" to \"$@\""
	$(CC) $(CFLAGS) -c $< -o $@






# objects folder
objFolder:
	@ echo "-> Creating /obj"
	mkdir -p obj


clean:
	@ echo "-> Cleaning up (delete /obj and \"$(PROJ_NAME).exe\")"
	rm -rf obj
	rm -f $(PROJ_NAME).exe
