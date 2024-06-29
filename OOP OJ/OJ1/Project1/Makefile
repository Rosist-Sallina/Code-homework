# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -std=c++11
DEBUGFLAGS = -g -DDEBUG

# Files
SOURCES = main.cpp Parser.cpp
HEADERS = Parser.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

# Standard build
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Debug build
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(EXECUTABLE)

# Object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all debug clean
