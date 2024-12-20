CXXFLAGS = -Wall -O3
OBJ_DIR  := obj
BIN_DIR  := .
TARGET = sudoku
INCLUDE = -Iinclude
LDFLAGS = -lm -L/usr/local/lib -lboost_regex

SRC     :=$(wildcard src/bind/*.cpp) $(wildcard src/*.cpp)
OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<


$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BIN_DIR)/$(TARGET) $(OBJECTS)

.PHONY: clean  all


clean:
	-@rm -rvf $(OBJ_DIR)
	-@rm -rvf $(BIN_DIR)/$(TARGET)