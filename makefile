# Makefile
CXX = g++
CXXFLAGS = -I./src -std=c++17 -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Explicitly list all source files
SOURCES = src/main.cpp \
	      src/ui/window.cpp \
	      src/models/animals/animal.cpp \
	      src/models/foods/food.cpp

# Create object files
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = simulation

# Default target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean