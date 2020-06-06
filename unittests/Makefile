include ../Makefile.extra

PACKAGE_NAME:=sudokutest

OBJ_DIR=obj

EXEC:=$(OBJ_DIR)/$(PACKAGE_NAME)

INCLUDES:= \
	-I../include \
	-Iinclude \
	-Igoogletest/include

CXXFLAGS+=$(INCLUDES)

LDFLAGS:=\
	-L../lib/obj \
	-Lgoogletest

LDLIBS:=\
	-lsudoku \
	-lstdc++ \
	-lpthread \
	-lgtest \
	-lgmock \
	-lgtest_main \
	-lgmock_main

SRC:=\
	main.cpp \
	SudokuUtilCheckerTest.cpp
	#SudokuPuzzleTest.cpp

OBJ_DIR=obj
OBJ:=$(SRC:%.cpp=%.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) -o $(EXEC) $(OBJ) $(LDLIBS)
	./$(EXEC)

.PHONY: clean
clean:
	$(RM) $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a $(EXEC)