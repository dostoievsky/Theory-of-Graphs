CC=cc
CFLAGS=-I./src -std=c11 -Wall
LDFLAGS=

TARGET=dijsktra 
SRC_DIR=src 

SOURCES!=find $(SRC_DIR) -name '*.c'
OBJECTS=$(SOURCES:.c=.o)

build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

TEST_TARGET=run_tests
TESTS_DIR=tests

TEST_SOURCES!=find $(TESTS_DIR) -name '*.c'
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)
MAIN_OBJECTS:=${SOURCES:.c=.o}
MAIN_OBJECTS:=${MAIN_OBJECTS:Nsrc/principal.o}

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS) $(MAIN_OBJECTS)
	@echo "Compiling tests..."
	$(CC) $(TEST_OBJECTS) $(MAIN_OBJECTS) -o $(TEST_TARGET) $(LDFLAGS)
	@echo "Running test..."
	./$(TEST_TARGET)
clean:
	rm -f $(TARGET) $(TEST_BINARIES) $(OBJECTS) $(TEST_OBJECTS) $(MAIN_OBJECTS)

.PHONY: build test clean

