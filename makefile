YELLOW=\033[1;33m
BLUE=\033[0;32m
DEF=\033[0m

CC=g++
CFLAGS=-std=c++11 -g

INCLUDE_DIR =include
OBJECTS_DIR=build
SRC_DIR =src
LIB_DIR =lib
BIN_DIR =bin

LIBS=-lm

_OBJ = main.o universo.o mundo.o hormiga.o
OBJ = $(patsubst %,$(OBJECTS_DIR)/%,$(_OBJ))

BIN_NAME = Langton

all: Langton

Langton: $(OBJ)
	$(CC) -o $(BIN_DIR)/$(BIN_NAME) $^ $(CFLAGS) $(LIBS)

$(OBJECTS_DIR)/hormiga.o: $(SRC_DIR)/hormiga.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJECTS_DIR)/mundo.o: $(SRC_DIR)/mundo.cpp
	$(CC) -c -o $@ $< $(CFLAGS)		

$(OBJECTS_DIR)/universo.o: $(SRC_DIR)/universo.cpp
	$(CC) -c -o $@ $< $(CFLAGS)	

$(OBJECTS_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	./$(BIN_DIR)/$(BIN_NAME)

.PHONY: clean

clean:
	@rm -f $(OBJECTS_DIR)/*.o *~ $(BIN_DIR)/*~ $(BIN_DIR)/*.exe
	@echo -e "${BLUE}Make: ${YELLOW}Objects Files and Executables cleaned!${DEF}"