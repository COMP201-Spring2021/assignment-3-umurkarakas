all: install test

install:
	gcc main.c -o main
clean:
	rm main
test:
	./main 10 75 20 7
