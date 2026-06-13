##  "makefile" for DiM.
##  https://www.github.com/rezoid-llc/DiM


CC        :=  clang
CCFLAGS   :=  -O3 -std=c23
.PHONY:   all run clean


TARGET := bld/DiM
SOURCE := $(wildcard src/*.c)


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

	@$(TARGET)

	
clean:
	@echo "Cleaning."
	@rm -f ./bld/*
	@echo "Finished."
