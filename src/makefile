# LDblLinkedList Makefile

output = ldbllinkedlist.o

CXXFLAGS = -D_GNU_SOURCE=1 -D_REENTRANT -pedantic -Wall

$(output): ldbllinkedlist.cpp ldbllinkedlist.h
	g++ $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(output)

