TARGET = prog
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

run: clean default
	clear
	./$(BIN_DIR)/$(TARGET) ./$(TEST_DIR)/7.c
	

default: create_dirs $(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf token-list.txt

create_dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(BIN_DIR)/$(TARGET): $(OBJ)
	gcc -g -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -g -c $< -o $@ -Iinclude
