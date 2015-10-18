CC=gcc
CC_FLAGS=-Wall
CUNIT_FLAGS=-lcunit -L/usr/local/lib
EXECUTABLE=lab3
TESTS_FOLDER=tests
TESTS=insertElement_test.c createElement_test.c deleteElement_test.c main.c
TESTS_SRC=$(TESTS:%=$(TESTS_FOLDER)/%)

all:
	$(CC) $(CC_FLAGS) element.c main.c -o $(EXECUTABLE)

build-tests:
	$(CC) $(CC_FLAGS) element.c  $(TESTS_SRC) -o tests/run_tests $(CUNIT_FLAGS)

run-tests: build-tests
	tests/run_tests

clean:
	@rm $(EXECUTABLE)
