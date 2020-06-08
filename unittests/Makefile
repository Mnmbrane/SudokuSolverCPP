include ../Makefile.extra

PACKAGE_NAME:=sudokutest

OBJ_DIR=obj

EXEC:=$(OBJ_DIR)/$(PACKAGE_NAME)

INCLUDES:= \
	-I.\
	-I../include \
	-Igoogletest/include

# don't turn on stack protect
# always stack smashing when lib has
# std container(vector, list)
CXXFLAGS+=$(INCLUDES)\
	-fno-stack-protector

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

LIB:=\
	../lib/$(OBJ_DIR)/libsudoku.a

SRC:=\
	PuzzleList.cpp \
	SudokuPuzzleTest.cpp

MAINOBJ:=$(OBJ_DIR)/main.o
OBJ:=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: make_utest
make_utest: $(OBJ_DIR) $(EXEC)

$(EXEC): $(OBJ_DIR) $(OBJ) $(MAINOBJ) $(LIB)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) -o $(EXEC) $(OBJ) $(LDLIBS)
	./$(EXEC)

.PHONY: run
run:
	./$(EXEC)

#No header file for main
$(MAINOBJ): $(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ): $(OBJ_DIR)/%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a $(EXEC)