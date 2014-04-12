CC=gcc
CFLAGS=-Wall -std=gnu99 -Wno-unused-result -lm 
TARGET=FP
OBJS = fp.c 

all: $(TARGET)
    
%.o: %.c
	$(CC) $(CFLAGS) -c $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) 
clean:
	rm -f *.o FP
