CC = g++

CFLAGS = -Werror -Wall -Wextra

SRC1 = trap.cpp 3.cpp
OBJ1 = $(SRC1:.cpp=.o)


# BUILD_DIR = /build/Quest_1

# Q1 = $(BUILD_DIR)
Q1 = 3.out

part3:
	$(CC) $(CFLAGS) $(SRC1) -c
	$(CC) $(CFLAGS) $(OBJ1) -o $(Q1)
	rm $(OBJ1)

all: part3