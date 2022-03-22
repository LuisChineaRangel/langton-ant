#################################################
# MAKEFILE
#################################################

CXX		 := g++
CXXFLAGS := -std=c++11 -pthread

BIN     := bin
SRC     := src
BUILD		:= build
INCLUDE := -Iinclude
LIB     := -Llib
EXECUTABLE  := $(notdir $(CURDIR))

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJS	:= $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) $(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cpp
	@echo "🚧 Building..."
	$(CXX) -c $(INCLUDE) -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*