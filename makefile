ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif

CXX		 := g++
CXXFLAGS := -std=c++11

BIN     := bin
SRC     := src
BUILD		:= build
INCLUDE := include
LIB     := lib
LIBRARIES := 
EXECUTABLE  := $(notdir $(CURDIR))

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJS	:= $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))

.PHONY: all clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cpp
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

clean:
	@echo "🧹 Clearing..."
	$(RM) $(call FixPath,bin/*)
	$(RM) $(call FixPath,build/*)