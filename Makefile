APPS = ./app
BIN = ./bin
INCLUDE = ./include
LIBDIR = ./lib
BUILD = ./build
SRC = ./src
FLAGS = -O2 -Wall -Werror -fsanitize=address -g
FLAGGLUT = -lGL -lGLU -lglut -lm

LIB = $(LIBDIR)/libdsa.a

all: \
    libeb \
	myapps

libeb: \
	$(BUILD)/array.o \
    $(BUILD)/execution_time.o \
	$(BUILD)/sorts.o 

myapps: \
	cleanapp \
	$(BIN)/app

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@ 

$(LIB): $(BUILD)/array.o $(BUILD)/execution_time.o $(BUILD)/sorts.o 
	ar rcs $@ $^

$(BIN)/%: $(APPS)/%.c $(LIB)
	gcc $(FLAGS) $< -L$(LIBDIR) -ldsa -I $(INCLUDE) -o $@ $(FLAGGLUT)

run:
	$(BIN)/app

runperf:
	perf stat -e cycles,instructions,cache-misses,branch-misses $(BIN)/app

clean:
	rm -rf $(BIN)/* $(BUILD)/* $(LIBDIR)/*

cleanapp:
	rm -rf $(BIN)/*