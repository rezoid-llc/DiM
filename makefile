main:
	@echo "Compiling."
	@rm -f ./bld/DiM
	@cc ./src/main.c -o ./bld/DiM
	@echo "Success."
run:
	@echo "Compiling."
	@rm -f ./bld/DiM
	@cc ./src/main.c -o ./bld/DiM
	@echo "Success."
	@./bld/DiM
clean:
	@rm -f ./bld/*
