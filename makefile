main:
	@echo "Compiling."
	@rm -f ./bld/DiM
	cc ./src/main.c -o ./bld/DiM
	@echo "Build Success."
run:
	@echo "Compiling."
	@rm -f ./bld/DiM
	cc ./src/main.c -o ./bld/DiM
	@echo "Build Success."
	@echo "" 
	@./bld/DiM
clean:
	@rm -f ./bld/*
	@echo "Removal Success."