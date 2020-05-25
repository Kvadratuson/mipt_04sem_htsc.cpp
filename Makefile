LIBRARY := htsc
TESTS   := utests

CFLAGS_DEBUG := -Wall --coverage

CC := g++

all: clean debug
	@echo DONE

debug: $(TESTS)

$(TESTS): $(TESTS).cpp $(LIBRARY).hpp $(LIBRARY).ipp
	$(CC) $< $(CFLAGS_DEBUG) -o $@

clean:
	rm -rf $(TESTS) *.gcno *.gcda *.gcov vgcore*

.PHONY: all debug clean
