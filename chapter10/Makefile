# path
# VPATH=src include bin header obj object lib
VPATH=include header headers src
TARGET=./bin/main
# define
CFLAGS=-Wall
CC=gcc

Cfiles=$(wildcard *.c)
Cfiles+=$(wildcard */*.c)
# CfilesDir=$(sort $(dir $(Cfiles)))

Hfiles=$(wildcard *.h)
Hfiles+=$(wildcard */*.h)
HfilesDir=$(sort $(dir $(Hfiles)))

SRCS=$(notdir $(Cfiles))

HEADERS=$(notdir $(Hfiles))

OBJ_DIR=./obj/
OBJECT_FILES=$(patsubst %.c,%.o,$(SRCS))
OBJECTS=$(addprefix $(OBJ_DIR), $(OBJECT_FILES))

CFLAGS+=-I
CFLAGS+=$(HfilesDir)

MKDIR_P=mkdir -p
OUT_DIR=obj bin

DELETECMD=rm -rf $(OBJECTS) $(TARGET)
ifeq ($(OS),Windows_NT)
	DELETECMD=erase /Q *.o $(TARGET) obj
	TARGET=.\bin\main.exe
	MKDIR_P=mkdir
endif

.PHONY:directories default all clean

all: directories default
directories: ${OUT_DIR}
default: $(TARGET)

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR} 

# rules
$(OBJ_DIR)%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
# run code
run:
	$(TARGET)
# clean
clean:
	$(DELETECMD)
