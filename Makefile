CC = g++
CFLAGS = -c -Wall -Wextra
TARGET = main

all: $(TARGET)

$(TARGET): main.o function.o polynomial.o rational.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o function.o polynomial.o rational.o

function.o: function.cpp function.h
	$(CC) -g $(CFLAGS) function.cpp

polynomial.o: polynomial.cpp polynomial.h function.h
	$(CC) -g $(CFLAGS) polynomial.cpp

rational.o: rational.cpp rational.h polynomial.h function.h
	$(CC) -g $(CFLAGS) rational.cpp

main.o: main.cpp function.h polynomial.h rational.h
	$(CC) -g $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~