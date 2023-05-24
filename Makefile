.PHONY: all run clean

CC := gcc-9

# compile flags
CFLAGS += -Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=1024
CFLAGS += -Wfloat-equal -Waggregate-return -Winline

SRC_DIR := src
OBJ_DIR := obj
DOCS_DIR := docs
DATA_DIR := data

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# executable
BIN := ticker

all: $(BIN)

money: $(BIN)
	./$(BIN)

debug: CFLAGS += -g3
debug: $(BIN)

clean: 
	@rm -rf $(BIN) $(OBJ_DIR)
	@rm $(DATA_DIR)/search_results

# creates object files from .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

# creates executable from object
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@