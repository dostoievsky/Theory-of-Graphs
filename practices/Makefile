CFLAGS=-I./src -std=c11 -Wall
LDFLAGS=

TARGET=BFS

SOURCES!=find src -name '*.c'
OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) compile_commands.json
