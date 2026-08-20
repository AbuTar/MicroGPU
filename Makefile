# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./include -MMD -MP


# Directories

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
BUILD_DIR = build



# Target executable

TARGET = $(BIN_DIR)/microgpu.exe


# Source files

SOURCES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/gpu.c


# Object files
# Put object files under build/

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS = $(OBJECTS:.o=.d)


# Default target
all: $(TARGET)


# Link all object files into executable

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(TARGET) -mconsole
	@echo "Build complete: $(TARGET)"


# Compile .c files to .o files

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# Automatically include dependency files

-include $(DEPS)


# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Clean complete"


# Rebuild everything
rebuild: clean all


# Run TinyGPU
run: $(TARGET)
	./$(TARGET)


.PHONY: all clean rebuild run