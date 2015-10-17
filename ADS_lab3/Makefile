CC=gcc
CC_FLAGS=-Wall
CUNIT_FLAGS=-lcunit -L/usr/local/lib
EXECUTABLE=lab3

all:
	$(CC) $(CC_FLAGS) element.c main.c -o $(EXECUTABLE)

build-tests:
	$(CC) $(CC_FLAGS) element.c tests/insert_test.c -o tests/insert_test $(CUNIT_FLAGS)
	$(CC) $(CC_FLAGS) element.c tests/createElement_test.c -o tests/createElement_test $(CUNIT_FLAGS)

run-tests:
	tests/insert_test
	tests/createElement_test

clean:
	@rm $(EXECUTABLE)
