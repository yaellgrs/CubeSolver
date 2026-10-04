CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude -Iinclude/Cube -Iinclude/Model -Iinclude/View
TARGET = cube_solver

SRC = $(wildcard src/*.cpp) \
	$(wildcard src/Cube/*.cpp) \
	$(wildcard src/Modele/*.cpp) \
	$(wildcard src/View/*.cpp)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
