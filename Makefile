GXX = g++
TLB = ar rcs
SRC = codejam.cpp
HDR = codejam.h
OBJ = codejam.o
LIB = libcodejam.a
TARGETDIR = ~/Library/codejam/

build:
	$(GXX) -c $(SRC) -o $(OBJ)
	$(TLB) $(LIB) $(OBJ)

clean:
	rm -f $(OBJ) $(LIB)