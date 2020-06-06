include ../Makefile.extra

LIBNAME:=sudoku

OBJ_DIR:=obj

INCLUDES:= \
	./../include

CXXFLAGS+=$(addprefix -I,$(INCLUDES))

SRC:=\
	SudokuUtilChecker.cpp \
	SudokuPuzzle.cpp

OBJ:=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

#make the library
$(OBJ_DIR)/lib$(LIBNAME).a: $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ): $(OBJ_DIR)/%.o: %.cpp $(INCLUDES)/%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) -r *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a