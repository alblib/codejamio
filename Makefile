GXX = clang++
TLB = ar rcs
SRC = ./src/codejam.cpp
HDR = ./include/codejam.h
OBJ = ./temp/codejam.o
LIB = ./lib/libcodejam.a
TARGETDIR = ~/Library/codejam/

build:
	$(GXX) -c $(SRC) -o $(OBJ)
	$(TLB) $(LIB) $(OBJ)
test:
	g++ 2017_quali_proba.cpp -L./lib -lcodejam -o test.out
	./test.out input.txt
	rm test.out

clean:
	rm -f $(OBJ)

