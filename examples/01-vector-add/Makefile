# 编译器
CC = gcc

# 编译选项
CFLAGS = -isystem /usr/local/cuda/targets/x86_64-linux/include -g -fPIC

# 源文件目录
SRC_DIR = .
KERNELS_DIR = ./kernels

# 目标文件目录
OBJ_DIR = ./obj

# 源文件
SRC_FILES = $(SRC_DIR)/add_kernel.c $(wildcard $(KERNELS_DIR)/*.c)

# 目标文件
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 静态库文件
TARGET_LIB = libkernels.a

# 默认目标
all: $(TARGET_LIB)

# 生成静态库
$(TARGET_LIB): $(OBJ_FILES)
	ar rcs $@ $^

# 编译源文件生成目标文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR) $(TARGET_LIB)

.PHONY: all clean
