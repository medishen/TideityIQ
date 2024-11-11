CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS =
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(SRC_DIR)/file_reader.c $(SRC_DIR)/utils.c $(SRC_DIR)/analyze/analyze.c $(SRC_DIR)/analyze/recursion.c $(SRC_DIR)/analyze/calc_complexity.c ${SRC_DIR}/analyze/loops.c $(SRC_DIR)/main.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC = tdq
INSTALL_DIR = /usr/local/bin

all: $(EXEC)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

# Install the binary to the specified directory
install: $(EXEC)
	cp $(EXEC) $(INSTALL_DIR)
	chmod +x $(INSTALL_DIR)/$(EXEC)
	echo "$(EXEC) has been installed to $(INSTALL_DIR)"

clean:
	rm -f $(OBJ_FILES) $(EXEC)
rebuild: clean all
.PHONY: all clean rebuild
