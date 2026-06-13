##  "makefile" for DiM.
##  https://www.github.com/rezoid-llc/DiM

CC      := clang
.PHONY: main run clean

main:
	@echo "Compiling."
	@rm -f ./bld/DiM

	@cc ./src/main.c -o ./bld/DiM

	@echo "Finished."
	
run:
	@echo "Compiling."
	@rm -f ./bld/DiM

	@cc ./src/main.c -o ./bld/DiM

	@echo "Finished."
	@echo ""

	@./bld/DiM

	
clean:
	@echo "Cleaning."
	@rm -f ./bld/*
	@echo "Finished."
