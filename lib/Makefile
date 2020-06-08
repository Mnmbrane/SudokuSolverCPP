include ../Makefile.extra

LIBNAME:=sudoku

OBJ_DIR:=obj

LIB:=$(OBJ_DIR)/lib$(LIBNAME).a 

INCLUDES:= \
	./../include

CXXFLAGS+=$(addprefix -I,$(INCLUDES))

SRC:=\
	SudokuCoord.cpp \
	SudokuUtilChecker.cpp \
	SudokuPuzzle.cpp

OBJ:=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: make_lib
make_lib: $(OBJ_DIR) $(LIB)

#make the library
$(LIB): $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ): $(OBJ_DIR)/%.o: %.cpp $(INCLUDES)/%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) -r *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a