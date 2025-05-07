LDLIBS = -lnetfilter_queue

all: netfilter-test

netfilter-test.o: netfilter-test.cpp

netfilter-test: netfilter-test.o
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f netfilter-test *.o


