CC=gcc
CC_FLAGS=-Wall -g
CUNIT_FLAGS=-lcunit -L/usr/local/lib
EXECUTABLE=lab3
TESTS_FOLDER=tests
TESTS=insertElement_test.c createElement_test.c listSize_test.c utils_test.c tasks_test.c tasks_array_test.c main.c
SOURCES=element.c utils.c tasks.c tasks_array.c
TESTS_SRC=$(TESTS:%=$(TESTS_FOLDER)/%)

all:
	$(CC) $(CC_FLAGS) $(SOURCES) main.c -o $(EXECUTABLE)

build-tests:
	$(CC) $(CC_FLAGS) -g $(SOURCES) $(TESTS_SRC) -o tests/run_tests $(CUNIT_FLAGS)

run-tests: build-tests
	tests/run_tests

check-memory-leaks: build-tests
	valgrind --track-origins=yes --tool=memcheck --leak-check=full tests/run_tests

clean:
	@rm $(EXECUTABLE)
