CC = gcc
C_FLAGS = -Wall
C_SRC  = crc8.c test.c
EXE = crc8_test


all:
	$(CC) $(C_FLAGS) $(C_SRC) -o $(EXE)

clean:
	rm -rf *~ *.o $(EXE)