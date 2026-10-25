CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c11 -Iinc
TARGET  = data/crypt
OBJS    = build/main.o build/encdec.o
BUILD   = build


.PHONY: clean all

all:$(TARGET)
$(TARGET): $(OBJS) | $(BUILD)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

build/main.o: src/main.c inc/encdec.h | $(BUILD)
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/encdec.o: src/encdec.c inc/encdec.h | $(BUILD)
	$(CC) $(CFLAGS) -c src/encdec.c -o build/encdec.o

$(BUILD):
	mkdir -p $(BUILD)



clean:
	rm -rf $(BUILD)
	rm -rf $(TARGET)