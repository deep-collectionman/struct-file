CC = gcc
CFLAGS = -I./headers

build:
	-@ $(CC) $(CFLAGS) ./source/file_object.c file.c -o file.bin
run: build
	-@ ./file.bin
clean:
	-@ $(RM) *.bin *.txt