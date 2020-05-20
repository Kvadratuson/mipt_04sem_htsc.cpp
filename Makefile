LIBRARY := htsc
TESTS   := utests

CFLAGS       := -Wall
CFLAGS_DEBUG := -Wall --coverage

CC := g++

all: clean release debug
	@echo DONE

release: lib$(LIBRARY).a

lib$(LIBRARY).a: $(LIBRARY).o
	ar rcs lib$(LIBRARY).a $<

$(LIBRARY).o: $(LIBRARY).cpp $(LIBRARY).hpp
	$(CC) $< -c $(CFLAGS) -o $@

debug: $(TESTS)

$(TESTS): $(TESTS).cpp lib$(LIBRARY)_debug.a
	$(CC) $^ $(CFLAGS_DEBUG) -o $@

lib$(LIBRARY)_debug.a: $(LIBRARY)_debug.o
	ar rcs $@ $<

$(LIBRARY)_debug.o: $(LIBRARY).cpp $(LIBRARY).hpp
	$(CC) $< -c $(CFLAGS_DEBUG) -o $@

clean:
	rm -rf *.o *.a $(TESTS) *.gcno *.gcda *.gcov vgcore*

.PHONY: all release debug clean
