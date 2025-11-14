CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11
TARGET  = courseApp
SRC     = main.c student.c course.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o