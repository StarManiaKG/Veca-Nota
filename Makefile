# Add variables for more fun
exe:=build/veca-nota

# Add definitions to generate the Veca-Nota binary
$(info Compiling files...)

all:
	c++ src/main.cpp src/string.cpp -o $(exe)
	@printf '\nVeca-Nota has been compiled! Enjoy!\n\n'
