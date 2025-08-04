# Makefile
CXX = g++
CXXFLAGS = -I./src -std=c++17 -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Build directory
BUILD_DIR = build

# Explicitly list all source files
SOURCES = src/main.cpp \
	      src/ui/window.cpp \
	      src/models/animals/animal.cpp \
	      src/models/foods/food.cpp

# Create object files in build directory, preserving folder structure
OBJECTS = $(SOURCES:src/%.cpp=$(BUILD_DIR)/%.o)

TARGET = simulation

# Default target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

# Rule to compile .cpp files to .o files, creating directories as needed
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Create build directory structure
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: all run clean