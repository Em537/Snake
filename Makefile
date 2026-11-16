CXX = g++
CFLAGS  = -Wall --debug -std=c++23 $(shell pkg-config --cflags raylib)
LDLIBS  = $(shell pkg-config --libs raylib)
PROJECT = game
SRC = src/main.cpp

$(PROJECT): $(SRC)
	$(CXX) $(CFLAGS) $(SRC) -o $@ $(LDLIBS)
	./game
run:
	$(CXX) $(CFLAGS) $(SRC) -o $@ $(LDLIBS)
	./game

clean:
	rm -rf $(PROJECT) $(PROJECT).dSYM
.PHONY: run clean
