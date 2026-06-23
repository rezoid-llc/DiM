##  "makefile" for DiM.
##  https://www.github.com/rezoid-llc/DiM


CC        :=  clang
CCFLAGS   :=  -fsanitize=address -O3 -std=c23
.PHONY:   all run clean


TARGET := bld/DiM
SOURCE := $(wildcard src/*.c)


FILE ?= prg.bin


all:
	@echo "Compiling."
	@rm -f ./bld/DiM

	@cc $(CCFLAGS) $(SOURCE) -o $(TARGET)

	@echo "Finished."


run:
	@echo "Compiling."
	@rm -f ./bld/DiM

	@cc $(CCFLAGS) $(SOURCE) -o $(TARGET)

	@echo "Finished."
	@echo ""

	@$(TARGET) $(FILE)

	
clean:
	@echo "Cleaning."
	@rm -f ./bld/*
	@echo "Finished."
