CC	= gcc
CFLAGS	= -Wall -Wextra -g3	-std=c11
TARGET	= sumApp
SRC	= program1.c sum.c

all: $(TARGET)

$(TARGET): $(SRC)	
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
